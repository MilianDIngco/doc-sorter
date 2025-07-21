#ifndef DRIVECLIENT
#define DRIVECLIENT

#include <string>
#include <vector>
#include "auth.hpp"

struct DriveFile {
  std::string id;
  std::string name;
  std::string mimeType;
  std::vector<std::string> parents;

  bool isDoc() {
    return mimeType == "application/vnd.google-apps.document";
  }

  bool isFolder() const {
      return mimeType == "application/vnd.google-apps.folder";
  }
  
};

class DriveClient {
  private: 
    DriveAuthorization& auth;

    size_t static writeCallback(void* contents, size_t size, size_t nmemb, std::string* data);

    std::string makeAuthRequest(const std::string& url);

    std::string url_encode(const std::string& str);

  public:
    DriveClient(DriveAuthorization& da) : auth(da) {};

    std::vector<DriveFile> listFiles(const std::string& query = "", int maxResults = 100);

    std::string getDocumentContent(const std::string& fileId);

    DriveFile getFileMetadata(const std::string& fileId);

};

#endif // DRIVECLIENT
