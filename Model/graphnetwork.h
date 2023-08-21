#ifndef CPP7_MLP_2_SRC_MODEL_GRAPHNETWORK_H_
#define CPP7_MLP_2_SRC_MODEL_GRAPHNETWORK_H_

#include <random>

#include "neuralnetwork.h"
namespace s21 {

class Neuron {
 public:
  float value_ = 0;
  std::vector<float> weights_;
  float bias_ = 0;
  float error_ = 0;
};
class Layer {
 public:
  std::vector<Neuron> neurons_;
  Layer(size_t amount_neurons, size_t amount_inputs);
};
class GraphNetwork : public NeuralNetwork {
 public:
  GraphNetwork() = delete;
  explicit GraphNetwork(std::vector<size_t> config);
  ~GraphNetwork() = default;
  void ForwardFeed() override;
  void BackPropagation() override;
  void InitFirstLayer(std::pair<Matrix, size_t> input) override;
  void CheckAnswer() override;
  void SaveWeights(std::string filename) override;
  bool LoadWeights(std::string filename) override;

 private:
  void InitNetwork(std::vector<size_t> config);
  std::vector<Layer> network_;
  size_t answer_ = 0;
};
}  // namespace s21
#endif  // CPP7_MLP_2_SRC_MODEL_GRAPHNETWORKL_H_