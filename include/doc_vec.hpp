#ifndef DOCVEC
#define DOCVEC

#include "drive_client.hpp"
#include <string>
#include <vector>

struct Document {
  std::string id; 
  std::string name; 

  std::vector<double> vector;

  Document(DriveFile file) : id(file.id), name(file.name) {};
};

struct Word {
  
};

class DocVector {
  private:
    DriveClient dc;

    void LoadStopWords();

    Word tokenize(const std::string& word);

    

  public: 
    DocVector(DriveClient dc) : dc(dc) {};

    Document VectorizeDoc(const std::string& doc_id);

};

#endif // DOCVEC
