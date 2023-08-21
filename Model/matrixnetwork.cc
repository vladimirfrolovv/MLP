#include "matrixnetwork.h"
namespace s21 {
void MatrixNetwork::ForwardFeed() {
  for (size_t i = 0; i < amount_layers_ - 1; ++i) {
    neurons_[i + 1] = weights_[i] * neurons_[i];
    for (size_t j = 0; j < amount_neurons_[i + 1]; ++j) {
      neurons_[i + 1](j, 0) =
          1.f / (1.f + expf(-(neurons_[i + 1](j, 0) + bias_[i](j, 0))));
    }
  }
}

MatrixNetwork::MatrixNetwork(std::vector<size_t> config) {
  InitNetwork(config);
}

void MatrixNetwork::BackPropagation() {
  auto error = neurons_;
  for (size_t i = 0; i < amount_neurons_[amount_layers_ - 1]; ++i) {
    float res = neurons_[amount_layers_ - 1](i, 0);
    if (i == answer_) {
      error[amount_layers_ - 1](i, 0) = res * (1 - res) * (1 - res);
      data_.mse += powf((1 - res), 2);
    } else {
      error[amount_layers_ - 1](i, 0) = res * (1 - res) * (0 - res);
      data_.mse += powf((0 - res), 2);
    }
  }

  float err = 0;
  for (size_t i = amount_layers_ - 2; i > 0; --i) {
    error[i] = weights_[i].Transpose() * error[i + 1];
    for (size_t j = 0; j < amount_neurons_[i]; ++j) {
      error[i](j, 0) *= neurons_[i](j, 0) * (1 - neurons_[i](j, 0));
    }
  }
  for (size_t i = 0; i < amount_layers_ - 1; ++i) {
    for (size_t j = 0; j < amount_neurons_[i + 1]; ++j) {
      err = error[i + 1](j, 0) * learning_rate_;
      bias_[i](j, 0) += err;
      for (size_t k = 0; k < amount_neurons_[i]; ++k) {
        weights_[i](j, k) += neurons_[i](k, 0) * err;
      }
    }
  }
}

void MatrixNetwork::SaveWeights(std::string filename) {
  std::ofstream file(filename);
  file << neurons_.size() << ' ';
  for (const auto &neuron : neurons_) {
    file << neuron.GetRows() << ' ';
  }
  file << '\n';
  for (size_t i = 0; i < weights_.size(); ++i) {
    for (size_t k = 0; k < weights_[i].GetRows(); ++k) {
      file << bias_[i](k, 0) << ' ';
      for (size_t j = 0; j < weights_[i].GetCols(); ++j) {
        file << weights_[i](k, j) << ' ';
      }
    }

    file << '\n';
  }
  file.close();
}

bool MatrixNetwork::LoadWeights(std::string filename) {
  std::ifstream file(filename);
  if (file) {
    std::vector<size_t> config;
    size_t size = 0;
    std::string line{};
    file >> size;
    size_t value = 0;
    config.reserve(size);
    for (size_t i = 0; i < size; ++i) {
      file >> value;
      config.push_back(value);
    }
    weights_.clear();
    bias_.clear();
    neurons_.clear();
    amount_neurons_.clear();
    InitNetwork(config);

    for (size_t i = 0; i < weights_.size(); ++i) {
      for (size_t k = 0; k < weights_[i].GetRows(); ++k) {
        file >> bias_[i](k, 0);
        for (size_t j = 0; j < weights_[i].GetCols(); ++j) {
          file >> weights_[i](k, j);
        }
      }
    }

    file.close();
    return true;
  } else {
    std::cout << "No Such File";
    return false;
  }
}

void MatrixNetwork::InitNetwork(std::vector<size_t> config) {
  std::random_device random_device;
  std::mt19937 generator(random_device());
  std::uniform_real_distribution<float> distribution(-1, 1);
  std::uniform_real_distribution<float> distribution_bias(0, 1);
  amount_layers_ = config.size();
  weights_.reserve(amount_layers_ - 1);
  neurons_.reserve(amount_layers_);
  amount_neurons_.reserve(amount_layers_);
  for (size_t i = 0; i < amount_layers_; i++) {
    amount_neurons_.push_back(config[i]);
    neurons_.emplace_back(config[i], 1);
    if (i != 0) {
      bias_.emplace_back(config[i], 1);
      for (size_t j = 0; j < config[i]; j++) {
        bias_[i - 1](j, 0) = distribution_bias(generator);
      }
    }
    if (i < amount_layers_ - 1) {
      weights_.emplace_back(config[i + 1], config[i]);
      for (size_t j = 0; j < config[i + 1]; j++) {
        for (size_t k = 0; k < config[i]; k++) {
          weights_[i](j, k) = distribution(generator);
        }
      }
    }
  }
}

void MatrixNetwork::InitFirstLayer(std::pair<Matrix, size_t> input) {
  answer_ = input.second;
  neurons_[0] = input.first;
}

void MatrixNetwork::CheckAnswer() {
  float max = neurons_[amount_layers_ - 1](0, 0);
  size_t idx_ans = 0;
  for (size_t j = 0; j < amount_neurons_[amount_layers_ - 1]; j++) {
    if (j == answer_) {
      data_.mse += powf((1 - neurons_[amount_layers_ - 1](j, 0)), 2);
    } else {
      data_.mse += powf((0 - neurons_[amount_layers_ - 1](j, 0)), 2);
    }
    if (neurons_[amount_layers_ - 1](j, 0) >= 0.5) {
      j == answer_ ? TP_++ : FP_++;
    } else {
      j == answer_ ? FN_++ : TN_++;
    }
    if (max < neurons_[amount_layers_ - 1](j, 0)) {
      max = neurons_[amount_layers_ - 1](j, 0);
      idx_ans = j;
    }
  }
  data_.answer = 65 + idx_ans;
}
}  // namespace s21