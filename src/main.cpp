#include "auth.hpp"
#include "drive_client.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

extern "C" {
  #include "libstemmer.h"
}

int main() {
  DriveAuthorization da;

  // Try to get access code first
  if (!da.loadTokens()) {
    // If fail, generate auth url
    std::cout << "Open this link in your browser: " << da.generateAuthURL() << std::endl;
    
    // Get auth code
    std::cout << "Enter authentication code: " << std::endl;
    std::string auth_code;
    std::getline(std::cin, auth_code);

    da.exchangeCodeToken(auth_code);
    try {
      da.loadTokens();
    } catch (std::runtime_error& err) {
      std::cerr << "Error loading tokens: " << err.what() << std::endl;
    }

    std::cout << "This is your access token " << da.getValidAccessToken() << std::endl;
  }

  // Make drive client
  DriveClient dc(da);

  // go thru each file, check if document 
  // check if document id exists in local json file
  // if not, vectorize it, then store (id, vector) pair in json file locally

  // then, run the k-means cluster algorithm

  sb_stemmer* stemmer = sb_stemmer_new("english", "UTF_8");
  if (!stemmer) {
    std::cerr << "ERROR: Could not create stemmer" << std::endl;
    return -1;
  }

  std::string input = "flauntedly";

  const sb_symbol* stemmed = sb_stemmer_stem(
    stemmer, 
    reinterpret_cast<const sb_symbol*>(input.c_str()),
    static_cast<int>(input.size())
  );

  std::string result(reinterpret_cast<const char*>(stemmed), sb_stemmer_length(stemmer));

  std::cout << input << ": " << result << std::endl;

}
