#ifndef CPP7_MLP_2_SRC_MODEL_MODEL_H_
#define CPP7_MLP_2_SRC_MODEL_MODEL_H_

#include "graphnetwork.h"
#include "matrixnetwork.h"
#include "neuralnetwork.h"
#include "reader.h"

namespace s21 {

class Model {
 public:
  Model() { network_ = new MatrixNetwork({784, 64, 64, 26}); };
  ~Model() { delete network_; };
  /// Function to check type of network and create derivative class from pointer
  /// on base class \param is_graph \param config config to create network
  void ChoiceNetwork(bool is_graph, std::vector<size_t> config);
  /// Function to train network
  /// \param filename
  /// \return data with accuracy, precision and others
  output_data_ Train(std::string filename);
  /// Function check test sample
  /// \param testfile
  /// \param share share of test sample
  /// \return data with accuracy, precision and others
  output_data_ Test(std::string testfile, float share);
  /// Function get answer from network which letter
  /// \param picture vector values of pixels
  /// \return
  output_data_ TestOneLetter(std::vector<float> picture);
  /// function implement cross-validation smaple
  /// \param filename sample filename
  /// \param k_group
  /// \return data with accuracy, precision and others
  output_data_ CrossValidation(std::string filename, size_t k_group);
  /// Save weights to file
  /// \param filename
  void SaveWeights(std::string filename);
  /// Load weights and bias from file
  /// \param filename weights
  /// \param is_graph type network
  /// \return
  bool LoadWeights(std::string filename, bool is_graph);

 private:
  NeuralNetwork* network_ = nullptr;
  Reader reader_;
  std::vector<std::pair<Matrix, size_t>> train_sample_{};
  std::vector<std::pair<Matrix, size_t>> test_sample_{};
};
}  // namespace s21
#endif  // CPP7_MLP_2_SRC_MODEL_MODEL_H_