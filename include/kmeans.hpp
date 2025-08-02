#ifndef KMEANS
#define KMEANS

#include "doc_vec.hpp"
#include <cstdlib>
#include <vector>

class KMeans {
  private:
    int k;
    double e;
    int n_features;
    std::vector<std::vector<double>> centroids;
    std::vector<double> centroid_deltas;
    std::vector<double> min_vector;
    std::vector<double> max_vector;

    bool validCentroidChanges();

    void getDocumentRange();

    void initCentroids();

    void assignClusters();

    void updateClusters();

    void predictClusters();

    double euclideanDist(std::vector<double> a, std::vector<double> b);
    
  public: 
    std::vector<Document*> dataset;

    KMeans(int k, double e, int chances, int n_features) {
      srand(0);
      this->setHyperParams(k, e, chances, n_features);
    }

    void setHyperParams(int k, double e, int chances, int n_features);

    void setDataset(std::vector<Document*>& dataset);

    void groupDocuments();

    void printInfo(DocVector& dv, int view_top_n = 3); 

    double getDocDistance(int index1, int index2);
};

#endif // KMEANS
