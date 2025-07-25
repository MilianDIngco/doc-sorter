#include "auth.hpp"
#include "doc_vec.hpp"
#include "drive_client.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <re2/re2.h>
#include <vector>

extern "C" {
  #include "libstemmer.h"
}

int main() {
  DriveAuthorization da;

  // Try to get access code first
  std::cout << "Trying to load tokens" << std::endl;
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
  std::cout << "Making drive client" << std::endl;
  DriveClient dc(da);

  // make document vectorizer
  std::cout << "Creating vectorizer" << std::endl;
  DocVector dv(dc);

  std::vector<DriveFile> files = dc.listFiles();
  DriveFile documentFile;
  for (int i = 0; i < (int) files.size(); i++) {
    if (files.at(i).isDoc()) {
      std::cout << "Trying to load file " << files.at(i).name << std::endl;
      dv.vectorizeDoc(files.at(i));
    }
  } 

  std::cout << "Calculating idf" << std::endl;
  dv.calculateIDF();

  std::cout << "Saving json file" << std::endl;
  dv.saveJSON();


  // go thru each file, check if document 
  // check if document id exists in local json file
  // if not, vectorize it, then store (id, vector) pair in json file locally

  // then, run the k-means cluster algorithm

}
