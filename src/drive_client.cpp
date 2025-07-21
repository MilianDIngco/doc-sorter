#include "drive_client.hpp"
#include "auth.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <stdexcept>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json; 

std::vector<DriveFile> DriveClient::listFiles(const std::string& query, int maxResults) {
  std::vector<DriveFile> files;

  std::string baseURL = "https://www.googleapis.com/drive/v3/files";
  std::string params = 
    "fields=" + this->url_encode("files(id,name,mimeType,parents)") + "&" +
    "pageSize=" + this->url_encode(std::to_string(maxResults));

  if (!query.empty()) {
    params += "&q=" + this->url_encode(query);
  }

  try {
    // make request
    std::string response = this->makeAuthRequest(baseURL + "?" + params);

    // parse response into json
    json responseJSON = json::parse(response);

    if (responseJSON.contains("files")) {
      for(const auto& fileJSON : responseJSON["files"]) {
        DriveFile file;
        file.id = fileJSON.value("id", "");
        file.name = fileJSON.value("name", "");
        file.mimeType = fileJSON.value("mimeType", "");

        if (fileJSON.contains("parents")) {
          for(const auto& parent : fileJSON["parents"]) {
            file.parents.push_back(parent);
          }
        }

        files.push_back(file);
      }
    }

  } catch (std::runtime_error e) {
    std::ostringstream err;
    err << "Error getting file list: " << e.what();
    throw std::runtime_error(err.str());
  }
  
  return files;
}

std::string DriveClient::getDocumentContent(const std::string& fileId) {
  // Use Google Docs API to export as plain text
  std::string url = "https://www.googleapis.com/drive/v3/files/" + fileId + "/export?mimeType=text/plain";
  
  try {
      return this->makeAuthRequest(url);
  } catch (const std::exception& e) {
      std::cerr << "Error getting document content: " << e.what() << std::endl;
      throw;
  }
}

DriveFile DriveClient::getFileMetadata(const std::string& fileId) {
  std::string url = "https://www.googleapis.com/drive/v3/files/" + fileId + "?fields=id,name,mimeType,parents";
  
  try {
      std::string response = this->makeAuthRequest(url);
      json fileJson = json::parse(response);
      
      DriveFile file;
      file.id = fileJson.value("id", "");
      file.name = fileJson.value("name", "");
      file.mimeType = fileJson.value("mimeType", "");
      
      if (fileJson.contains("parents")) {
          for (const auto& parent : fileJson["parents"]) {
              file.parents.push_back(parent);
          }
      }
      
      return file;
      
  } catch (const std::exception& e) {
      std::cerr << "Error getting file metadata: " << e.what() << std::endl;
      throw;
  }
}

std::string DriveClient::makeAuthRequest(const std::string& url) {
  // initialize curl
  CURL* curl;
  CURLcode res;
  std::string response;

  curl = curl_easy_init();
  if (!curl) {
    throw std::runtime_error("Failed to init CURL");
  }

  try {
    // set up headers with authentication
    struct curl_slist* headers = nullptr;
    std::string authHeaders = "Authorization: Bearer " + this->auth.getValidAccessToken();
    headers = curl_slist_append(headers, authHeaders.c_str());

    // Configure CURL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, DriveClient::writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

    res = curl_easy_perform(curl);

    // Check HTTP status code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    
    // Cleanup
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    
    if (res != CURLE_OK) {
        throw std::runtime_error("CURL request failed: " + std::string(curl_easy_strerror(res)));
    }
    
    if (response_code >= 400) {
        std::ostringstream err;
        err << "HTTP error " << response_code << ": " << response;
        throw std::runtime_error(err.str());
    }
    
    return response;
      
  } catch (...) {
      curl_easy_cleanup(curl);
      throw;
  }
    
}

std::string DriveClient::url_encode(const std::string& str) {
    CURL* curl = curl_easy_init();
    if (!curl) return "";
    
    char* encoded = curl_easy_escape(curl, str.c_str(), str.length());
    std::string result(encoded);
    curl_free(encoded);
    curl_easy_cleanup(curl);
    return result;
}

size_t DriveClient::writeCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
  size_t totalSize = size * nmemb;
  data->append((char*)contents, totalSize);
  return totalSize;
}
