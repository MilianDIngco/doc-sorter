#include "doc_vec.hpp"
#include "drive_client.hpp"
#include "re2/re2.h"
#include "re2/stringpiece.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

std::vector<Document> DocVector::loadDocuments(const std::string& filepath) {

}

void DocVector::saveDocument(Document document) {

}

void DocVector::calculateIDF(std::vector<Document>& documents) {
  int n_documents = documents.size();

  for (int i = 0; i < n_documents; i++) {
    Document* curr = &documents.at(i);

    // Resize tf_vector.size() so all are the same
    if ((int) curr->tf_vector.size() < total_words) 
      curr->tf_vector.resize(total_words);

    curr->tf_idf_vector.resize(total_words);

    for (auto pair : this->dictionary) {
      // Normalize term frequency with the document's highest frequency word
      double term_freq = 0.5 + (0.5 * (double) curr->tf_vector.at(pair.second) / curr->highest_freq);
      double doc_freq = std::log10(n_documents / this->doc_freq.at(pair.second));

      curr->tf_idf_vector.at(pair.second) = doc_freq * term_freq;
    }
  }
}

Document DocVector::vectorizeDoc(const std::string& doc_id) {
  // Get document content
  DriveFile file = this->dc.getFileMetadata(doc_id);
  std::string content = this->dc.getDocumentContent(doc_id);

  Document doc(file);

  // Tokenize the document
  SmartWord head = this->tokenizeDoc(content);
  doc.head = std::move(head);

  // Remove stop words
  this->removeStopWords(doc);

  // Normalize document
  this->normalizeDoc(doc);

  // Do document term frequency vectorization
  this->tfVectorizeDoc(doc);

  return doc;
}

void DocVector::test() {
  Document doc;
  std::string content = "Hello there now it's so bad im writing on some documents on my laptop and its heating up my balls, i really wish that i didn't have to poop so bad right now.";
  std::cout << content << std::endl;
  std::cout << "Tokenizing" << std::endl;
  doc.head = tokenizeDoc(content);
  std::cout << "Removing stop words" << std::endl;
  this->removeStopWords(doc);
  std::cout << "Normalizing" << std::endl;
  this->normalizeDoc(doc);
  std::cout << doc.toString() << std::endl;

  std::cout << "Vectorizing doc" << std::endl;
  this->tfVectorizeDoc(doc);

  for (auto pair : this->dictionary) {
    std::cout << pair.first << ": " << doc.tf_vector.at(pair.second) << std::endl;
  }
}

void DocVector::tfVectorizeDoc(Document& doc) {
  if ((int) doc.tf_vector.size() < this->total_words) {
    doc.tf_vector.resize(this->total_words);
  }

  // Go through each word in the doc and check if it exists in the hashmap, if so, get its index
  doc.applyToDoc([this, &doc](std::string& str){
    // Add new word to dictionary
    if (!this->dictionary.contains(str)) {
      this->dictionary[str] = this->total_words++;
    }
    // Get word's index
    int index = this->dictionary[str];

    // Resize it if too small
    int vec_size = doc.tf_vector.size();
    if (vec_size <= index) {
      doc.tf_vector.resize((vec_size * 2 > index) ? vec_size * 2 : index * 2);
    } 

    // Increment term frequency vector
    doc.tf_vector.at(index)++;

    // Keep track of highest frequency to normalize for lengthy documents
    if (doc.tf_vector.at(index) > doc.highest_freq) 
      doc.highest_freq = doc.tf_vector.at(index);
  });

  // Update global doc frequency vector
  if ((int) doc_freq.size() < total_words)
    doc_freq.resize(total_words);

  for (auto pair : this->dictionary) {
    if (doc.tf_vector.at(pair.second) > 0)
      this->doc_freq.at(pair.second)++;
  }
}

void DocVector::normalizeDoc(Document& doc) {

  doc.applyToDoc([this](std::string& str){ 
    const sb_symbol* stemmed = sb_stemmer_stem(
      stemmer, 
      reinterpret_cast<const sb_symbol*>(str.c_str()), 
      static_cast<int>(str.size())
    );

    std::string res(reinterpret_cast<const char*>(stemmed), sb_stemmer_length(stemmer));
    str = res;
  });

}

void DocVector::removeStopWords(Document& doc) {
  WordNode* curr = doc.head.get();
  while (curr != nullptr) {
    // Check if curr is in the stop words set
    if (stop_words.contains(curr->word)) {
      WordNode* temp = curr->next.get();
      curr->unlink();
      curr = temp;
    }

    curr = curr->next.get();
  }
}

void DocVector::loadStopWords() {
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
  }
}

SmartWord DocVector::tokenizeDoc(std::string& content) {
  std::vector<std::string> tokens;

  // (?:\\s|^|\") checks for, but doesn't group strings that have this preceding
  // ([\\w]+) groups all the characters that are word characters
  // (?:\\s|:?\\s|$|[.!,;\"]) checks for strings that end with whitespace, : then whitespace, end of string, or punctuation
  re2::RE2 pattern("(?:\\s|^|\")([\\w']+)(?:\\:?\\s|$|[.!,;\"])");
  re2::StringPiece input_piece(content);

  WordNode* prev = nullptr;
  SmartWord head;
  std::string token;
  while(re2::RE2::FindAndConsume(&input_piece, pattern, &token)) {
    // Initialize the current node
    toLowercase(token);
    SmartWord current = std::make_unique<WordNode>(token);

    // keep track of the previous one
    if (prev) {
      current->prev = prev;
      prev->next = std::move(current);
      // set previous one = current
      prev = prev->next.get();
    } else {
      head = std::move(current);
      prev = head.get();
    }

  }

  return head;
}

void DocVector::toLowercase(std::string& str) {
  std::transform(str.begin(), str.end(), str.begin(), 
                 [](unsigned char c){ return std::tolower(c); });
}
