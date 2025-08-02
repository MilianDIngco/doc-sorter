#include "kmeans.hpp"
#include "doc_vec.hpp"
#include <cmath>
#include <cstdlib>
#include <limits>
#include <vector>

bool KMeans::validCentroidChanges() {
  bool changed = false;
  for (int i = 0; i < (int) this->centroid_deltas.size(); i++) {
    if (this->centroid_deltas.at(i) > this->e) {
      changed = true;
      break;
    }
  }

  return changed;
}

void KMeans::getDocumentRange() {
  this->min_vector.resize(this->n_features);
  this->max_vector.resize(this->n_features);

  for (int i = 0; i < (int) min_vector.size(); i++) {
    double value = this->dataset.at(0)->tf_idf_vector.at(i);
    min_vector.at(i) = value;
    max_vector.at(i) = value;
  }

  for (int doc_index = 0; doc_index < (int) this->dataset.size(); doc_index++) {
    Document* doc = this->dataset.at(doc_index);
    for (int feature_index = 0; feature_index < this->n_features; feature_index++) {
      double tf_idf = doc->tf_idf_vector.at(feature_index);
      double min = this->min_vector.at(feature_index);
      double max = this->max_vector.at(feature_index);
      this->min_vector.at(feature_index) = (tf_idf < min) ? tf_idf : min;
      this->max_vector.at(feature_index) = (tf_idf > max) ? tf_idf : max;
    }
  }
}

void KMeans::initCentroids() {
  /*std::vector<bool> used(this->dataset.size());
  for (int i = 0; i < (int) used.size(); i++)
    used.at(i) = false;
  for (int centroid_index = 0; centroid_index < this->k; centroid_index++) {
    int index = 0;
    do {
      index = rand() % this->dataset.size();
    } while (used.at(index));
    used.at(index) = true;

    this->centroids.at(centroid_index) = this->dataset.at(index)->tf_idf_vector;
  }
  */
 
  for (int centroid_index = 0; centroid_index < (int) this->centroids.size(); centroid_index++) {
    for (int feature_index = 0; feature_index < this->n_features; feature_index++) {
      double min = this->min_vector.at(feature_index);
      double max = this->max_vector.at(feature_index);
      this->centroids.at(centroid_index).at(feature_index) = (max - min) * ((double) rand() / RAND_MAX) + min;
    }
  }
  
}

void KMeans::assignClusters() {
  for (int dataset_index = 0; dataset_index < (int) this->dataset.size(); dataset_index++) {
    Document* doc = this->dataset.at(dataset_index);
    double min_dist = std::numeric_limits<double>::max();
    int cluster_index = 0;
    for (int centroid_index = 0; centroid_index < this->k; centroid_index++) {
      double dist = this->euclideanDist(doc->tf_idf_vector, this->centroids.at(centroid_index));
      if (dist < min_dist) {
        min_dist = dist;
        cluster_index = centroid_index;
      }
    }

    doc->group = cluster_index;
  }
}

void KMeans::updateClusters() {
  // Go through each centroid and keep track of its old position
  for (int centroid_index = 0; centroid_index < this->k; centroid_index++) {
    std::vector<double> new_centroid(this->n_features);
    bool empty = true;

    // Get the mean feature of all documents in the cluster
    for (int feature_index = 0; feature_index < this->n_features; feature_index++) {
      int clusterSize = 0;
      new_centroid.at(feature_index) = 0;

      // Check if the document is in the cluster, if so, consider it in the mean
      for (int dataset_index = 0; dataset_index < (int) this->dataset.size(); dataset_index++) {
        if (this->dataset.at(dataset_index)->group == centroid_index) {
          new_centroid.at(feature_index) += this->dataset.at(dataset_index)->tf_idf_vector.at(feature_index);
          clusterSize++;
        }
      }
      if (clusterSize != 0) {
        new_centroid.at(feature_index) /= clusterSize;
        empty = false;
      } else {
        double min = this->min_vector.at(feature_index);
        double max = this->max_vector.at(feature_index);
        new_centroid.at(feature_index) = (max - min) * ((double) rand() / RAND_MAX) + min;
      }
    }

    // update centroid deltas, if it was empty, give it another chance before going below epsilon
    if (!empty) {
      this->centroid_deltas.at(centroid_index) = this->euclideanDist(this->centroids.at(centroid_index), new_centroid);
    } else {
      this->centroid_deltas.at(centroid_index) -= this->e;
    }

    std::cout << centroid_index << " moved " << this->centroid_deltas.at(centroid_index) << std::endl;
    
    // reassign to old centroids
    this->centroids.at(centroid_index) = new_centroid;

  }
}

void KMeans::predictClusters() {

}

double KMeans::euclideanDist(std::vector<double> a, std::vector<double> b) {
  double sum = 0;
  
  for (int feature_index = 0; feature_index < this->n_features; feature_index++) {
    double amount = a.at(feature_index) - b.at(feature_index);
    sum += amount * amount;
  }

  return sqrt(sum);
}

// public functions
    
void KMeans::setHyperParams(int k, double e, int chances, int n_features) {
  this->n_features = n_features;
  this->k = k;
  this->centroids.resize(this->k);
  this->centroid_deltas.resize(this->k);

  // Ensure centroid deltas won't immediately make program skip
  this->e = e;
  for (int i = 0; i < (int) centroid_deltas.size(); i++) {
    this->centroid_deltas.at(i) = this->e * chances;
  }

  // Initialize centroids with random values so far
  for (int i = 0; i < (int) centroids.size(); i++) {
    this->centroids.at(i).resize(this->n_features);   
  }
}

void KMeans::setDataset(std::vector<Document*>& dataset) {
  this->dataset = dataset;
  if (this->k > (int) this->dataset.size()) {
    std::cout << "k resized from " << this->k << " to " << this->dataset.size() << std::endl;
    this->k = this->dataset.size();
  }
  this->getDocumentRange();
  this->initCentroids();
}

void KMeans::groupDocuments() {
  while (this->validCentroidChanges()) {
    this->assignClusters();
    this->updateClusters();
  }

}

void KMeans::printInfo(DocVector& dv, int view_top_n) {
  std::vector<std::vector<int>> clusters(this->k);
  for (int i = 0; i < (int) this->dataset.size(); i++) {
    std::cout << i << ", " << this->dataset.at(i)->group << ": " << this->dataset.at(i)->name << std::endl;
    clusters.at(this->dataset.at(i)->group).push_back(i);
  }

  for (int i = 0; i < this->k; i++) {
    std::cout << "Cluster " << i << " has " << clusters.at(i).size() << " documents." << std::endl;
    for (int n = 0; n < (int) clusters.at(i).size(); n++) {
      int index = clusters.at(i).at(n);
      std::cout << "\t" << n << ", " << index << ": " << this->dataset.at(index)->name << std::endl;
      std::cout << "\t\t(";
      for (int cent_dist = 0; cent_dist < this->k; cent_dist++) {
        double dist = this->euclideanDist(this->dataset.at(index)->tf_idf_vector, this->centroids.at(cent_dist));
        std::cout << cent_dist << ": " << dist << ", ";
      }
      std::cout << ")" << std::endl;
        // copy tfidf vector
      std::vector<double> tfidf = this->dataset.at(index)->tf_idf_vector;
      std::vector<int> high_freq_index(view_top_n);

      // Find the top n most frequent words
      for (int j = 0; j < view_top_n; j++) {
        double max = -1;
        int curr_max_index = 0;

        // Look for the most frequent word
        for (int feature_index = 0; feature_index < (int) tfidf.size(); feature_index++) {
          if (tfidf.at(feature_index) > max) {
            max = tfidf.at(feature_index);
            curr_max_index = feature_index;
          }
        }

        // Ensure this high freq word isn't counted
        tfidf.at(curr_max_index) = -1;
        high_freq_index.at(j) = curr_max_index;
      }

      // print out the top n words using the dictionary
      for (int j = 0; j < view_top_n; j++) {
        std::string word = "";
        for (auto [key, index] : dv.dictionary) {
          if (index == high_freq_index.at(j)) {
            word = key;
            break;
          }
        }

        std::vector<double> new_tfidf = this->dataset.at(index)->tf_idf_vector;
        std::cout << "\t\t" << j << ": " << word << " freq: " << new_tfidf.at(high_freq_index.at(j)) << std::endl;
      }
    }
  }

  for (int i = 0; i < (int) clusters.size(); i++) {
    std::cout << "cluster " << i << ": " << clusters.at(i).size() << " documents" << std::endl;
  }
}

double KMeans::getDocDistance(int index1, int index2) {
  return this->euclideanDist(dataset.at(index1)->tf_idf_vector, dataset.at(index2)->tf_idf_vector);
}
