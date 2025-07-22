#include "doc_vec.hpp"
#include "drive_client.hpp"
#include <string>

Document DocVector::VectorizeDoc(const std::string& doc_id) {
  // Get document content
  DriveFile file = this->dc.getFileMetadata(doc_id);
  std::string content = this->dc.getDocumentContent(doc_id);

  Document doc(file);

  

  return doc;
}

