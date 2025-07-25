#include "doc_vec.hpp"
#include "drive_client.hpp"
#include "re2/re2.h"
#include "re2/stringpiece.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

void DocVector::loadDocuments(const std::string& filepath) {
  try {
    docJSON = loadJson(filepath);
  } catch(std::runtime_error e) {
    // Load info
    throw e;
  }

  // Load dictionary
  std::cout << "Loading dictionary" << std::endl;
  for (auto& [word, index] : docJSON["dictionary"].items()) {
    this->dictionary[word] = index;
    this->total_words++;
  }

  // Load doc_freq
  std::cout << "Loading doc frequency" << std::endl;
  this->doc_freq.resize(this->total_words);
  for (auto& [index, amount] : docJSON["doc_freq"].items()) {
    this->doc_freq.at(std::stoi(index)) = amount;
  }

  // Load documents
  std::cout << "Loading documents" << std::endl;
  for (auto& [doc_id, doc_data] : docJSON["document"].items()) {
    std::unique_ptr<Document> doc = std::make_unique<Document>();
    
    doc->id = doc_data.value("id", "");
    doc->name = doc_data.value("name", "");
    doc->modifiedTime = doc_data.value("modifiedTime", "");
    doc->highest_freq = doc_data.value("highest_freq", 0);

    std::cout << "Name: " << doc->name << std::endl;
    // Load tf_vector
    int tf_vector_size = doc_data.value("tf_vector_size", 0);
    doc->tf_vector.resize(tf_vector_size);
    for (int i = 0; i < tf_vector_size; i++) {
      int amt = doc_data["tf_vector"][std::to_string(i)];
      doc->tf_vector.at(i) = amt;
    }

    // load tf_idf_vector
    int tf_idf_vector_size = doc_data.value("tf_idf_vector_size", 0);
    doc->tf_idf_vector.resize(tf_idf_vector_size);
    for (int i = 0; i < tf_idf_vector_size; i++) {
      double amt = doc_data["tf_idf_vector"][std::to_string(i)];
      doc->tf_idf_vector.at(i) = amt;
    }

    this->doc_map[doc->id] = std::move(doc);
  }
}

void DocVector::saveDocument(Document* doc) {
  docJSON["document"][doc->id]["id"] = doc->id;
  docJSON["document"][doc->id]["name"] = doc->name;
  docJSON["document"][doc->id]["modifiedTime"] = doc->modifiedTime;
  docJSON["document"][doc->id]["highest_freq"] = doc->highest_freq;
  docJSON["document"][doc->id]["tf_vector_size"] = (int) doc->tf_vector.size();
  docJSON["document"][doc->id]["tf_idf_vector_size"] = (int) doc->tf_idf_vector.size();

  // load tf_vector
  for (int i = 0; i < (int) doc->tf_vector.size(); i++) {
    docJSON["document"][doc->id]["tf_vector"][std::to_string(i)] = doc->tf_vector.at(i);
  }

  // load tf_idf_vector
  for (int i = 0; i < (int) doc->tf_idf_vector.size(); i++) {
    docJSON["document"][doc->id]["tf_idf_vector"][std::to_string(i)] = doc->tf_idf_vector.at(i);
  }
}

void DocVector::saveJSON() {
  // save dictionary
  for (auto& [word, index] : this->dictionary) {
    docJSON["dictionary"][word] = index;
  }

  // save doc_freq
  for (int i = 0; i < this->doc_freq.size(); i++) {
    docJSON["doc_freq"][std::to_string(i)] = this->doc_freq.at(i);
  } 

  // save documents
  for (auto& [id, doc] : this->doc_map) {
    std::cout << "Saving " << doc->id << ": " << doc->name << std::endl;
    this->saveDocument(doc.get());
  }

  // save da file
  std::ofstream tokenFile(this->doc_filepath);
  tokenFile << this->docJSON.dump(2);
}

void DocVector::calculateIDF() {
  int n_documents = this->doc_map.size();
  for (auto& [id, doc] : this->doc_map) {
    // Resize tf_vector.size() so all are the same
    if ((int) doc->tf_vector.size() < total_words) 
      doc->tf_vector.resize(total_words);

    doc->tf_idf_vector.resize(total_words);

    for (auto pair : this->dictionary) {
      // Normalize term frequency with the document's highest frequency word
      int highest_freq_nozero = (doc->highest_freq == 0) ? 1 : doc->highest_freq;
      double term_freq = 0.5 + (0.5 * (double) doc->tf_vector.at(pair.second) / highest_freq_nozero);
      double d_freq_nozero = (this->doc_freq.at(pair.second) == 0) ? 1 : this->doc_freq.at(pair.second);
      double doc_freq = std::log10(n_documents / d_freq_nozero);

      doc->tf_idf_vector.at(pair.second) = doc_freq * term_freq;
    }
  }

}

Document& DocVector::vectorizeDoc(DriveFile& file) {
  if (!file.isDoc()) {
    throw std::runtime_error("ERROR: Vectorize Doc passed non-document file");
  }
  // Check if file_id exists in docMap, if so, check time last modified
  if (doc_map.contains(file.id) && 
      doc_map[file.id]->modifiedTime == file.modifiedTime) {
      std::cout << "Using cached document" << std::endl;
    return *doc_map[file.id].get();
  }

  // Get document content
  std::cout << "Getting content" << std::endl;
  std::string content = this->dc.getDocumentContent(file.id);

  SmartDoc doc = std::make_unique<Document>(file);

  // Tokenize the document
  std::cout << "Tokenizing document" << std::endl;
  SmartWord head = this->tokenizeDoc(content);
  doc->head = std::move(head);

  // Remove stop words
  std::cout << "Removing stop words" << std::endl;
  this->removeStopWords(*doc);

  // Normalize document
  std::cout << "Normalizing document" << std::endl;
  this->normalizeDoc(*doc);

  // Do document term frequency vectorization
  std::cout << "Calculating term frequency" << std::endl;
  this->tfVectorizeDoc(*doc);

  // Add to map
  doc_map[file.id] = std::move(doc);

  return *doc_map[file.id].get();
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
    } else {
      curr = curr->next.get();
    }
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

json DocVector::loadJson(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filepath);
  }

  json j;
  file >> j;
  return j;
}
