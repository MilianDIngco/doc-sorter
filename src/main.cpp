#include "auth.hpp"
#include "doc_vec.hpp"
#include "drive_client.hpp"
#include "kmeans.hpp"
#include <cctype>
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
  std::cout << "Main: Trying to load tokens" << std::endl;
  if (!da.loadTokens()) {
    // If fail, generate auth url
    std::cout << "Main: Open this link in your browser: " << da.generateAuthURL() << std::endl;
    
    // Get auth code
    std::cout << "Main: Enter authentication code: " << std::endl;
    std::string auth_code;
    std::getline(std::cin, auth_code);

    da.exchangeCodeToken(auth_code);
    try {
      da.loadTokens();
    } catch (std::runtime_error& err) {
      std::cerr << "Error loading tokens: " << err.what() << std::endl;
    }

    std::cout << "Main: This is your access token " << da.getValidAccessToken() << std::endl;
  }

  // Make drive client
  std::cout << "Main: Making drive client" << std::endl;
  DriveClient dc(da);

  // make document vectorizer
  std::cout << "Main: Creating vectorizer" << std::endl;
  DocVector dv(dc);

  std::vector<DriveFile> files = dc.listFiles();
  std::vector<Document*> docs;
  docs.reserve(files.size());
  for (int i = 0; i < (int) files.size(); i++) {
    if (files.at(i).isDoc()) {
      std::cout << "Main: Trying to load file " << files.at(i).name << std::endl;
      try {
      docs.push_back(dv.vectorizeDoc(files.at(i)));
      } catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
      }
    }
  } 

  std::cout << "Main: Calculating idf" << std::endl;
  dv.calculateIDF();

  std::cout << "Main: Saving json file" << std::endl;
  dv.saveJSON();

  std::cout << "Main: Running k-means clustering" << std::endl;

  // Perform kmeans clustering
  std::string input;

  KMeans km(5, 0.1, 100, dv.getTotalWords());
  do {
    // Ask for k value
    int k = 1;
    double e = 0.1;
    std::cout << "Enter how many clusters should be considered: " << std::endl;
    std::cin >> input;
    k = std::stoi(input);
    std::cout << "Enter the lower bound for centroid movement: " << std::endl;
    std::cin >> input;
    e = std::stod(input);

    km.setHyperParams(k, e, 100, dv.getTotalWords());

    km.setDataset(docs);

    km.groupDocuments();

    km.printInfo(dv);

    std::cout << "Quit? enter q to quit, anything else to continue" << std::endl;
    std::cin >> input;

  } while (std::tolower(input.at(0)) != 'q');

  do {
    // list all document namespace 
    km.printInfo(dv, 1);

    // get index of docs to compare
    std::cout << "Enter document index 1: " << std::endl;
    std::cin >> input;
    int index1 = std::stoi(input);

    std::cout << "Enter document index 2: " << std::endl;
    std::cin >> input;
    int index2 = std::stoi(input);

    std::cout << "Distance: " << km.getDocDistance(index1, index2) << std::endl;

    std::cout << "Quit? enter q to quit, anything else to continue" << std::endl;
    std::cin >> input;
  } while(std::tolower(input.at(0)) != 'q');
}
