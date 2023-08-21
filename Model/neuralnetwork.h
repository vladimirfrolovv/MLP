#ifndef CPP7_MLP_2_SRC_MODEL_NEURALNETWORK_H_
#define CPP7_MLP_2_SRC_MODEL_NEURALNETWORK_H_
#include "fastmatrix.h"
#include "fstream"
#include "ostream"
#include "struct_output_data.h"
namespace s21 {
class NeuralNetwork {
 public:
  NeuralNetwork() = default;
  virtual ~NeuralNetwork() = default;
  virtual void ForwardFeed() = 0;
  virtual void BackPropagation() = 0;
  virtual void InitFirstLayer(std::pair<Matrix, size_t> input) = 0;
  virtual void CheckAnswer() = 0;
  virtual void SaveWeights(std::string filename) = 0;
  virtual bool LoadWeights(std::string filename) = 0;
  output_data_ GetData(size_t size);
  output_data_& ClearMse();
  float& GetLearningRate();

 protected:
  output_data_ data_{};
  float learning_rate_ = 0.3;
  double TP_ = 0, TN_ = 0, FP_ = 0, FN_ = 0;
};

}  // namespace s21

#endif  // CPP7_MLP_2_SRC_MODEL_NEURALNETWORK_H_