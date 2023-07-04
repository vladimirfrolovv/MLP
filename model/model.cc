#include "model.h"
namespace s21 {

void NeuralNetwork::InitLayers(int size, std::vector<int> n) {
  //  std::srand(time(NULL));
  std::random_device random_device;  // Источник энтропии.
  std::mt19937 generator(random_device());
  std::uniform_real_distribution<float> distribution(-1, 1);
  std::uniform_real_distribution<float> distribution_bias(0, 1);
  amount_hide_layers_ = size;

  weights.reserve(amount_hide_layers_ - 1);
  neurons.reserve(amount_hide_layers_);
  amount_neurons_.reserve(amount_hide_layers_);
  error.reserve(amount_hide_layers_);
  for (int i = 0; i < amount_hide_layers_; i++) {
    amount_neurons_.push_back(n[i]);
    neurons.emplace_back(n[i], 1);
    error.emplace_back(n[i], 1);
    if (i != 0) {
      bias.emplace_back(n[i], 1);
    }
    if (i < amount_hide_layers_ - 1) {
      // TODO подумать как какой слой будет лежать в строках а какой в колонкаъ
      weights.emplace_back(n[i + 1], n[i]);
      for (int j = 0; j < n[i + 1]; j++) {
        for (int k = 0; k < n[i]; k++) {
          weights[i](j, k) = distribution(generator);
          //            bias[i](j, k) = distribution(generator);
          //            (rand() % 100) * 0.01 / amount_neurons_[i]
        }
      }
    }
  }
  /// TESTS
  //  neurons[0](0,0) = 0.35;
  //    neurons[0](1,0) = 0.9;
  //    weights[0](0,0) = 0.1;
  //    weights[0](1,0) = 0.4;
  //    weights[0](0,1) = 0.8;
  //    weights[0](1,1) = 0.6;
  //    weights[1](0,0) = 0.3;
  //    weights[1](0,1) = 0.9;
  //    neurons[0](0,0) = 1;
  //    neurons[0](1,0) = 0;
  //    neurons[0](2,0) = 1;
  //
  //    weights[0](0,0) = 0.2;
  //    weights[0](1,0) = -0.3;
  //
  //    weights[0](0,1) = 0.4;
  //    weights[0](1,1) = 0.1;
  //
  //    weights[0](0,2) = -0.5;
  //    weights[0](1,2) = 0.2;
  //
  //    weights[1](0,0) = -0.3;
  //    weights[1](0,1) = -0.2;
  //
  //    bias[1](0,0) = -0.4;
  //    bias[1](0,1) = 0.2;
  //
  //    bias[2](0,0) = 0.1;
  //    ForwardFeed();
  ////    std::cout << neurons[2](0,0) << '\n';
  //    BackPropagation();
  //    ForwardFeed();
  //    std::cout << neurons[2](0,0) << '\n';

  //    std::cout <<  weights[0](0,0) <<'\n';
  //    std::cout <<  weights[0](1,0) << '\n';
  //    std::cout <<  weights[0](0,1) << '\n';
  //    std::cout <<  weights[0](1,1) << '\n';
  //    std::cout <<  weights[0](0,2) << '\n';
  //    std::cout <<  weights[0](1,2) << '\n';
  //    std::cout <<  weights[1](0,0) << '\n';
  //    std::cout <<  weights[1](0,1) << '\n';
  //    std::cout <<  bias[2](0,0) << '\n';
  //    std::cout <<  bias[1](0,1) << '\n';
  //    std::cout <<  bias[1](0,0) << '\n';

  //    std::cout << weights[0](1,1)<< '\n';
  //
  //    std::cout << weights[1](0,0)<< '\n';
  //    std::cout << weights[1](0,1)<< '\n';

  //    BackPropagation();

  //  for (int i = 0; i < amount_hide_layers_ - 1; ++i) {
  //    for (int j = 0; j < amount_neurons_[i]; ++j) {
  //      bias[i](j, 0) = distribution_bias(generator);
  ////              (rand() % 50) * 0.01 / (amount_neurons_[i] + 15);
  //    }
  //  }
}
void NeuralNetwork::ForwardFeed() {
  for (int i = 0; i < amount_hide_layers_ - 1; ++i) {
    neurons[i + 1] = weights[i] * neurons[i] + bias[i];
    for (int j = 0; j < amount_neurons_[i + 1]; ++j) {
      neurons[i + 1](j, 0) = 1.f / (1.f + exp(-(neurons[i + 1](j, 0))));
    }
  }
}
inline float NeuralNetwork::ActiveDer(float value) {
  return value * (1.f - value);
}
inline float NeuralNetwork::ActivateFunc(float value) {
  return 1.f / (1.f + exp(-value));
}

void NeuralNetwork::Train(const std::string &trainfile, int epoch) {
  parser->ReadFile(trainfile, 't');
  size_t size = parser->train.size();
  auto ff_b = std::chrono::steady_clock::now();
  for (int j = 0; j < epoch; j++) {
    int count = 0, idx_ans = 0;
    float max = 0, check = 0;
    size_t i = 0;
    while (i < size) {
      answer = parser->train[i].second;
      while (count < neurons[0].GetRows()) {
        neurons[0](count, 0) = parser->train[i].first(count, 0);
        count++;
      }
      i++;
      count = 0;
      ForwardFeed();
      BackPropagation();
    }
    learning_rate *= 0.65;
    std::cout << j << std::endl;
  }
  auto ff_e = std::chrono::steady_clock::now();
  auto res_ff = std::chrono::duration_cast<std::chrono::seconds>(ff_e - ff_b);
  std::cout << "The time: " << res_ff.count() << " ms\n";
}

void NeuralNetwork::Test(std::string testfile) {
  parser->ReadFile(testfile, 's');
  size_t size = parser->test.size();
  size_t i = 0;
  int count = 0, idx_ans = 0;
  float max = 0, check = 0, lines = 0;
  while (i < size) {
    answer = parser->test[i].second;
    while (count < amount_neurons_[0]) {
      neurons[0](count, 0) = parser->test[i].first(count, 0);
      count++;
    }
    i++;
    count = 0;
    lines++;
    ForwardFeed();
    max = neurons[amount_hide_layers_ - 1](0, 0);
    for (int j = 0; j < amount_neurons_[amount_hide_layers_ - 1]; j++) {
      if (max < neurons[amount_hide_layers_ - 1](j, 0)) {
        max = neurons[amount_hide_layers_ - 1](j, 0);
        idx_ans = j;
      }
    }
    if (idx_ans == answer) {
      check++;
    }
  }

  std::cout << (check / lines) * 100.0 << '\n';
  std::cout << check << '\n';
}
void NeuralNetwork::BackPropagation() noexcept {
  for (int i = 0; i < amount_neurons_[amount_hide_layers_ - 1]; ++i) {
    float res = neurons[amount_hide_layers_ - 1](i, 0);
    if (i == answer) {
      error[amount_hide_layers_ - 1](i, 0) = res * (1 - res) * (1 - res);
    } else {
      error[amount_hide_layers_ - 1](i, 0) = res * (1 - res) * (0 - res);
    }
  }
  float err = 0;
  for (int i = amount_hide_layers_ - 2; i > 0; --i) {
    error[i] = weights[i].Transpose() * error[i + 1];
    for (int j = 0; j < amount_neurons_[i]; ++j) {
      error[i](j, 0) *= neurons[i](j, 0) * (1 - neurons[i](j, 0));
    }
  }
  for (int i = 0; i < amount_hide_layers_ - 1; ++i) {
    for (int j = 0; j < amount_neurons_[i + 1]; ++j) {
      err = error[i + 1](j, 0) * learning_rate;
      bias[i](j, 0) += err;
      for (int k = 0; k < amount_neurons_[i]; ++k) {
        weights[i](j, k) += neurons[i](k, 0) * err;
      }
    }
  }
}
void NeuralNetwork::SaveWeights() {}
std::vector<Matrix> NeuralNetwork::GetWeights() const { return weights; }
std::vector<Matrix> &NeuralNetwork::GetNeurons() { return neurons; }
}  // namespace s21
