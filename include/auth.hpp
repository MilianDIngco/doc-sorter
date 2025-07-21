#ifndef AUTH
#define AUTH

#include <chrono>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DriveAuthorization {
  private:
    std::string access_token;
    std::string refresh_token;
    std::string auth_code;
    std::string state_security;
    std::string client_id;
    std::string client_secret;
    std::string clientJSON = "/home/milianingco/.config/doc-sorter/client_secret_1067603821863-81tl8ggokq2dsi595667duoqpdqb4tqp.apps.googleusercontent.com.json";
    std::string token_filepath = ".tokens.json";
    std::chrono::time_point<std::chrono::high_resolution_clock> access_expiry_time;

    json loadJson(const std::string& filepath);

    bool generateRandomState();

    bool getClientDetails();

    std::string url_encode(const std::string& str);
  
    size_t static writeCallback(void* contents, size_t size, size_t nmemb, std::string* data);

  public:
    DriveAuthorization();

    bool loadTokens();

    std::string generateAuthURL();

    bool exchangeCodeToken(const std::string& auth_code);

    bool refreshAccessToken();

    bool saveTokens();

    std::string getValidAccessToken();

};

#endif // AUTH
