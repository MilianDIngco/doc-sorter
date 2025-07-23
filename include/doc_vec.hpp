#ifndef DOCVEC
#define DOCVEC

#include "drive_client.hpp"
#include <string>
#include <unordered_set>
#include <vector>

struct Document {
  std::string id; 
  std::string name; 

  std::vector<double> vector;

  Document(DriveFile file) : id(file.id), name(file.name) {};
};

class DocVector {
  private:
    DriveClient dc;
    std::string stop_words_filepath = "./data/EN-Stopwords.txt";
    std::unordered_set<std::string> stop_words;

    void LoadStopWords();

    void NormalizeDoc(std::string& content);

    void RemoveStopWords(std::string& content);

    std::vector<std::string> TokenizeDoc(std::string& content);

  public: 
    DocVector(DriveClient dc) : dc(dc) { 
      LoadStopWords();
    };

    Document VectorizeDoc(const std::string& doc_id);

};

#endif // DOCVEC
