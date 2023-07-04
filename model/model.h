//#ifndef CPP7_MLP_2_SRC_MODEL_MODEL_H_
//#define CPP7_MLP_2_SRC_MODEL_MODEL_H_

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <random>
#include <sstream>
#include <thread>
#include <vector>

//#include "fastmatrix.h"
#include "parser.h"

namespace s21 {
//    Class Model {
//    Model() = default;
//    ~Model() = default;
//    public:
class NeuralNetwork {
 public:
  NeuralNetwork() { parser = new Reader; }
  ~NeuralNetwork() { delete parser; }
  void InitLayers(int size, std::vector<int> n);
  void ForwardFeed();
  inline float ActivateFunc(float value);
  inline float ActiveDer(float value);
  void BackPropagation() noexcept;
  void SaveWeights();
  void Train(const std::string& trainfile, int epoch);
  void Test(std::string testfile);
  std::vector<Matrix> GetWeights() const;
  std::vector<Matrix>& GetNeurons();

 public:
  // TODO private
  int amount_hide_layers_{};
  std::vector<int> amount_neurons_;  // 400
  std::vector<Matrix> bias;          // шаг
  std::vector<Matrix> weights;
  std::vector<Matrix> neurons;
  size_t answer = 0;
  std::vector<Matrix> error;
  int parse_counter = 0;
  double err = 0;
  Reader* parser = nullptr;
};
//    };
}  // namespace s21
