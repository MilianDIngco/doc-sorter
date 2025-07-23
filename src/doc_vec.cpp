#include "doc_vec.hpp"
#include "drive_client.hpp"
#include "re2/re2.h"
#include "re2/stringpiece.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

Document DocVector::VectorizeDoc(const std::string& doc_id) {
  // Get document content
  DriveFile file = this->dc.getFileMetadata(doc_id);
  std::string content = this->dc.getDocumentContent(doc_id);

  Document doc(file);

  

  return doc;
}


void DocVector::LoadStopWords() {
  std::ifstream file(this->stop_words_filepath);
  if (!file) {
    throw std::runtime_error("Failed to load stop word file");
  }
  
  // while there's words, get them.
  re2::RE2 pattern("(?:\\s|^|\")([\\w']+)(?:\\:?\\s|$|[.!,;\"])");
  std::string stop_word;
  std::string tokenized_stop_word;
  while (std::getline(file, stop_word)) {
    re2::StringPiece stop_word_piece(stop_word);
    re2::RE2::FindAndConsume(&stop_word_piece, pattern, &tokenized_stop_word);
    this->stop_words.insert(tokenized_stop_word);
    std::cout << tokenized_stop_word << std::endl;
  }
}

std::vector<std::string> DocVector::TokenizeDoc(std::string& content) {
  std::vector<std::string> tokens;

  // (?:\\s|^|\") checks for, but doesn't group strings that have this preceding
  // ([\\w]+) groups all the characters that are word characters
  // (?:\\s|:?\\s|$|[.!,;\"]) checks for strings that end with whitespace, : then whitespace, end of string, or punctuation
  re2::RE2 pattern("(?:\\s|^|\")([\\w']+)(?:\\:?\\s|$|[.!,;\"])");
  re2::StringPiece input_piece(content);

  std::string token;
  while(re2::RE2::FindAndConsume(&input_piece, pattern, &token)) {
    tokens.push_back(token);
  }

  return tokens;
}
