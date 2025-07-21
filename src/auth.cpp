#include "auth.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <curl/curl.h>
#include <string>
#include <sstream>

using json = nlohmann::json;

DriveAuthorization::DriveAuthorization() {
  // Generate client id 
  if (!this->getClientDetails())
    throw std::runtime_error("Failed to get client id from secret client json");

  // Generate random state
  if (!this->generateRandomState())
    throw std::runtime_error("Failed to generate security state");
}

std::string DriveAuthorization::getValidAccessToken() {
    auto now = std::chrono::system_clock::now();
    if (now >= this->access_expiry_time) {
      try {
        refreshAccessToken();
      } catch (std::runtime_error& e) {
        std::ostringstream err;
        err << "Failed to refresh access token: " << e.what();
        throw std::runtime_error(err.str());
      }
    }
    return this->access_token;
}

std::string DriveAuthorization::generateAuthURL() {
  std::string baseURL = "https://accounts.google.com/o/oauth2/v2/auth";

  std::string params = 
    "client_id=" + this->url_encode(this->client_id) + "&" +
    "redirect_uri=" + this->url_encode("urn:ietf:wg:oauth:2.0:oob") + "&" + 
    "response_type=" + this->url_encode("code") + "&" + 
    "scope=" + this->url_encode("https://www.googleapis.com/auth/drive https://www.googleapis.com/auth/documents.readonly") + "&" + 
    "access_type=" + this->url_encode("offline") + "&" + 
    "state=" + this->url_encode(this->state_security); 

  return baseURL + "?" + params;
}

bool DriveAuthorization::loadTokens() {
  // load da json file
  json tokenJSON;
  try {
    tokenJSON = loadJson(this->token_filepath);
  } catch(std::runtime_error& e) {
    // token json doesn't exist yet
    return false;
  }

  // get da tokens if existin
  if (tokenJSON.contains("access_token"))
    this->access_token = tokenJSON["access_token"];
  else
    throw std::runtime_error("access_token from .tokens.json does not exist");

  if (tokenJSON.contains("refresh_token"))
    this->refresh_token = tokenJSON["refresh_token"];
  else
    throw std::runtime_error("refresh_token from .tokens.json does not exist");

  if (tokenJSON.contains("access_expiry_time")) {
    std::string expiry_str = tokenJSON["access_expiry_time"];
    long long expiry_sec = std::stoll(expiry_str);

    // Convert seconds since epoch to system_clock time_point
    auto duration_since_epoch = std::chrono::seconds(expiry_sec);
    this->access_expiry_time = std::chrono::system_clock::time_point(duration_since_epoch);
  } else {
    throw std::runtime_error("access_expiry_time no exist");
  }

  return true;
}

bool DriveAuthorization::refreshAccessToken() {
    // Check if we have a refresh token
    if (this->refresh_token.empty()) {
        throw std::runtime_error("No refresh token available. Need to re-authenticate.");
    }

    // Set up POST data
    std::string postData = 
        "client_id=" + this->url_encode(this->client_id) +
        "&client_secret=" + this->url_encode(this->client_secret) +
        "&refresh_token=" + this->url_encode(this->refresh_token) +
        "&grant_type=refresh_token";

    // Set up CURL
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to set up curl");
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://oauth2.googleapis.com/token");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DriveAuthorization::writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Set headers
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Perform the request
    res = curl_easy_perform(curl);

    // Cleanup
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::ostringstream error;
        error << "CURL failed during token refresh: " << curl_easy_strerror(res);
        throw std::runtime_error(error.str());
    }

    // Parse response
    try {
        json responseJSON = json::parse(response);

        // Check for errors
        if (responseJSON.contains("error")) {
            std::ostringstream err;
            err << "Token refresh error: " << responseJSON["error_description"];
            throw std::runtime_error(err.str());
        }

        // Get new access token
        if (responseJSON.contains("access_token")) {
            this->access_token = responseJSON["access_token"];
        } else {
            throw std::runtime_error("Token refresh error: no access token in response");
        }

        // Update expiry time using system_clock
        int json_expiry_sec = responseJSON.value("expires_in", 3600);
        auto now = std::chrono::system_clock::now();
        auto token_lifetime = std::chrono::seconds(json_expiry_sec);
        auto lifetime_buffer = std::chrono::minutes(5);
        this->access_expiry_time = now + token_lifetime - lifetime_buffer;

        // Note: Refresh token usually stays the same, but sometimes Google issues a new one
        if (responseJSON.contains("refresh_token")) {
            this->refresh_token = responseJSON["refresh_token"];
        }

        // Save updated tokens
        return saveTokens();

    } catch (const nlohmann::json::exception& e) {
        std::ostringstream err;
        err << "JSON parsing error during token refresh: " << e.what() 
            << std::endl << "Response: " << response;
        throw std::runtime_error(err.str());
    }
}

bool DriveAuthorization::exchangeCodeToken(const std::string& auth_code) {
  // Set up post data
  std::string postData = 
        "code=" + this->url_encode(auth_code) + "&" +
        "client_id=" + this->url_encode(this->client_id) + "&" +
        "client_secret=" + this->url_encode(this->client_secret) + "&" +
        "redirect_uri=" + this->url_encode("urn:ietf:wg:oauth:2.0:oob") + "&" +
        "grant_type=" + this->url_encode("authorization_code");

  // Set up CURL
  CURL* curl;
  CURLcode res;
  std::string response;

  curl = curl_easy_init();
  if (!curl) {
    throw std::runtime_error("Failed to initialize CURL");
  }

  curl_easy_setopt(curl, CURLOPT_URL, "https://oauth2.googleapis.com/token");
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DriveAuthorization::writeCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  // Set headers
  struct curl_slist* headers = nullptr;
  headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  
  // Perform the request
  res = curl_easy_perform(curl);
  
  // Cleanup
  curl_slist_free_all(headers);
  curl_easy_cleanup(curl);
  
  if (res != CURLE_OK) {
    std::ostringstream error;
    error << "CURL failed: " << curl_easy_strerror(res);
    throw std::runtime_error(error.str());
  }

  // get response string, turn into json, parse it to get access tokens
  try {
    json responseJSON = json::parse(response);

    // check for errors
    if (responseJSON.contains("error")) {
      std::ostringstream err;
      err << "Token exchange error: " << responseJSON["error_description"] << std::endl;
      throw std::runtime_error(err.str());
    }

    // get da tokens
    if (responseJSON.contains("access_token")) {
      this->access_token = responseJSON["access_token"];
    } else {
      throw std::runtime_error("Token exchange error, no access token");
    }

    if (responseJSON.contains("refresh_token")) {
      this->refresh_token = responseJSON["refresh_token"];
    } else {
      throw std::runtime_error("Token exchange error, no refresh token");
    }

    // get and set expiry time using system_clock
    int json_expiry_sec = responseJSON.value("expires_in", 3600);

    auto now = std::chrono::system_clock::now();
    auto token_lifetime = std::chrono::seconds(json_expiry_sec);
    auto lifetime_buffer = std::chrono::minutes(5);

    this->access_expiry_time = now + token_lifetime - lifetime_buffer;

    return saveTokens();

  } catch (const json::exception& e) {
    std::ostringstream err;
    err << e.what() << std::endl << "Response: " << response;
    throw std::runtime_error(err.str());
  }
}

bool DriveAuthorization::saveTokens() {
  // Convert system_clock time_point to seconds since epoch
  auto time_t_expiry = std::chrono::duration_cast<std::chrono::seconds>(
      this->access_expiry_time.time_since_epoch()
  ).count();

  json tokenJSON;
  tokenJSON["access_token"] = this->access_token;
  tokenJSON["refresh_token"] = this->refresh_token;
  tokenJSON["access_expiry_time"] = std::to_string(time_t_expiry);

  std::ofstream tokenFile(this->token_filepath);
  tokenFile << tokenJSON.dump(2);

  return true;
}

json DriveAuthorization::loadJson(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filepath);
  }

  json j;
  file >> j;
  return j;
}

bool DriveAuthorization::generateRandomState() {
  this->state_security = "state_" + std::to_string(std::time(nullptr));
  return true;
}

bool DriveAuthorization::getClientDetails() {
  json secret;
  std::string clientId;
  try {
    secret = loadJson(this->clientJSON);
  } catch(std::runtime_error& e) {
    throw e;
  }
  
  if (secret.contains("installed") && secret["installed"].contains("client_id")) {
    this->client_id = secret["installed"]["client_id"];
  } else {
    throw std::runtime_error("Secret client json, unexpected structure");
  }

  if (secret.contains("installed") && secret["installed"].contains("client_secret")) {
    this->client_secret = secret["installed"]["client_secret"];
  } else {
    throw std::runtime_error("Secret client json, unexpected structure");
  }
  
  return true;
}

std::string DriveAuthorization::url_encode(const std::string& str) {
    CURL* curl = curl_easy_init();
    if (!curl) return "";
    
    char* encoded = curl_easy_escape(curl, str.c_str(), str.length());
    std::string result(encoded);
    curl_free(encoded);
    curl_easy_cleanup(curl);
    return result;
}

// Callback for writing response data
size_t DriveAuthorization::writeCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
    size_t totalSize = size * nmemb;
    data->append((char*)contents, totalSize);
    return totalSize;
}
