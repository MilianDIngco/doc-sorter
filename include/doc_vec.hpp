#ifndef DOCVEC
#define DOCVEC

#include "drive_client.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

extern "C" {
  #include "libstemmer.h"
}

struct WordNode {
  std::string word;
  WordNode* prev;
  std::unique_ptr<WordNode> next;

  WordNode(std::string word, WordNode* prev, WordNode* next) : word(word), prev(prev), next(next) {};
  WordNode(std::string word) : WordNode(word, nullptr, nullptr) {};
  WordNode() : WordNode("", nullptr, nullptr) {};

  void unlink() {
    if (prev) this->prev->next = std::move(this->next);
    if (next) this->next->prev = this->prev;
  };
};

struct Document {
  std::string id; 
  std::string name; 
  std::string modifiedTime;

  std::unique_ptr<WordNode> head;
  std::vector<int> tf_vector;
  std::vector<double> tf_idf_vector;

  int highest_freq;

  Document(std::string id, std::string name, std::string modifiedTime) : id(id), name(name), modifiedTime(modifiedTime) {
    tf_vector.resize(10);
    highest_freq = 0;
  };
  Document(DriveFile file) : Document(file.id, file.name, file.modifiedTime) {};
  Document() : Document("", "", "") {};

  void applyToDoc(std::function<void(std::string&)> function) {
    WordNode* curr = head.get();
    while (curr != nullptr) {
      function(curr->word);
      curr = curr->next.get();
    }
  }

  std::string toString() {
    std::string res = "";

    applyToDoc([&res](std::string& str) {
      res += str + " ";
    });

    return res;
  }

};

using SmartWord = std::unique_ptr<WordNode>;

class DocVector {
  private:
    DriveClient dc;
    std::string stop_words_filepath = "./data/EN-Stopwords.txt";
    std::unordered_set<std::string> stop_words;
    sb_stemmer* stemmer;
    std::unordered_map<std::string, int> dictionary;
    std::vector<int> doc_freq;
    int total_words;

    void saveDocument(Document document);

    std::vector<Document> loadDocuments(const std::string& filepath);

    void loadStopWords();

    void tfVectorizeDoc(Document& doc);

    void normalizeDoc(Document& doc);

    void removeStopWords(Document& doc);

    SmartWord tokenizeDoc(std::string& content);

    static void toLowercase(std::string& str);

  public: 
    DocVector(DriveClient dc) : dc(dc) { 
      loadStopWords();
      this->stemmer = sb_stemmer_new("english", "UTF_8");
      if (!stemmer) {
        throw std::runtime_error("ERROR: Could not create stemmer");
      }
      total_words = 0;
    };

    Document vectorizeDoc(const std::string& doc_id);

    void calculateIDF(std::vector<Document>& documents);

    void test();

};

#endif // DOCVEC
