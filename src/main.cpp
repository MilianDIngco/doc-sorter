#include "auth.hpp"
#include "drive_client.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char** argv) {
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

  std::vector<DriveFile> files = dc.listFiles();

  for (auto file : files) {
    std::cout << file.id << ": " << file.name << ", type: " << file.mimeType << std::endl;
  }

  for (auto file : files) {
    if (file.isDoc()) {
      std::string doc_content = dc.getDocumentContent(file.id);
      std::cout << doc_content << std::endl;
      break;
    }
  }

}
