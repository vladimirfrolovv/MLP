#ifndef CPP7_MLP_2_SRC_MODEL_MATRIXNETWORK_H_
#define CPP7_MLP_2_SRC_MODEL_MATRIXNETWORK_H_
#include <random>

#include "neuralnetwork.h"
namespace s21 {

class MatrixNetwork : public NeuralNetwork {
 public:
  MatrixNetwork() = delete;
  explicit MatrixNetwork(std::vector<size_t> config);
  ~MatrixNetwork() = default;
  void ForwardFeed() override;
  void BackPropagation() override;
  void InitFirstLayer(std::pair<Matrix, size_t> input) override;
  void CheckAnswer() override;
  void SaveWeights(std::string filename) override;
  bool LoadWeights(std::string filename) override;

 private:
  void InitNetwork(std::vector<size_t> config);
  size_t amount_layers_ = 4;
  std::vector<size_t> amount_neurons_{};
  std::vector<Matrix> bias_, weights_{}, neurons_{};
  size_t answer_{};
  std::vector<std::pair<Matrix, size_t>> train_sample_{};
  std::vector<std::pair<Matrix, size_t>> test_sample_{};
};
}  // namespace s21
#endif  // CPP7_MLP_2_SRC_MODEL_MATRIXNETWORK_H_