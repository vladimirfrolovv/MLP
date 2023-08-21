#include "graphnetwork.h"

namespace s21 {

Layer::Layer(size_t amount_neurons, size_t amount_inputs) {
  std::random_device random_device;
  std::mt19937 generator(random_device());
  std::uniform_real_distribution<float> distribution(-1, 1);
  for (size_t i = 0; i < amount_neurons; ++i) {
    Neuron neuron;
    for (size_t j = 0; j < amount_inputs; ++j) {
      neuron.weights_.push_back(distribution(generator));
    }

    neurons_.push_back(neuron);
  }
}
void GraphNetwork::ForwardFeed() {
  for (size_t i = 1; i < network_.size(); ++i) {
    Layer& prev_layer = network_[i - 1];
    Layer& curr_layer = network_[i];
    for (auto& neuron : curr_layer.neurons_) {
      float sum = 0.0;
      for (size_t k = 0; k < prev_layer.neurons_.size(); ++k) {
        sum += prev_layer.neurons_[k].value_ * neuron.weights_[k];
      }
      neuron.value_ = 1.f / (1.f + expf(-(sum)) + neuron.bias_);
    }
  }
}
void GraphNetwork::BackPropagation() {
  for (size_t i = 0; i < network_.back().neurons_.size(); ++i) {
    float res = network_.back().neurons_[i].value_;
    if (i == answer_) {
      network_.back().neurons_[i].error_ = res * (1 - res) * (1 - res);
      data_.mse += powf((1 - res), 2);
    } else {
      network_.back().neurons_[i].error_ = res * (1 - res) * (0 - res);
      data_.mse += powf((0 - res), 2);
    }
  }
  for (size_t i = network_.size() - 2; i > 0; --i) {
    Layer& curr_layer = network_[i];
    Layer& next_layer = network_[i + 1];
    for (size_t j = 0; j < curr_layer.neurons_.size(); ++j) {
      float output = curr_layer.neurons_[j].value_;
      float sum = 0.0;
      for (auto& neuron : next_layer.neurons_) {
        sum += neuron.weights_[j] * neuron.error_;
      }
      curr_layer.neurons_[j].error_ = output * (1 - output) * sum;
    }
  }

  for (size_t i = network_.size() - 1; i > 0; --i) {
    Layer& currLayer = network_[i];
    Layer& prevLayer = network_[i - 1];

    for (auto& neuron : currLayer.neurons_) {
      for (size_t k = 0; k < prevLayer.neurons_.size(); ++k) {
        float output = prevLayer.neurons_[k].value_;
        float delta = neuron.error_;
        neuron.weights_[k] += learning_rate_ * output * delta;
      }
    }
  }
}

GraphNetwork::GraphNetwork(std::vector<size_t> config) { InitNetwork(config); }

void GraphNetwork::InitNetwork(std::vector<size_t> config) {
  for (size_t i = 0; i < config.size(); ++i) {
    if (i == 0) {
      network_.emplace_back(Layer(config[i], 0));
    } else {
      network_.emplace_back(Layer(config[i], config[i - 1]));
    }
  }
}

void GraphNetwork::SaveWeights(std::string filename) {
  std::ofstream file(filename);
  file << network_.size() << ' ';
  for (const auto& net : network_) {
    file << net.neurons_.size() << ' ';
  }
  file << '\n';
  for (size_t i = 1; i < network_.size(); ++i) {
    for (const auto& neuron : network_[i].neurons_) {
      file << neuron.bias_ << ' ';
      for (const auto& weight : neuron.weights_) {
        file << weight << ' ';
      }
    }

    file << '\n';
  }
  file.close();
}

bool GraphNetwork::LoadWeights(std::string filename) {
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
    network_.clear();
    InitNetwork(config);
    for (size_t i = 1; i < network_.size(); ++i) {
      for (auto& neuron : network_[i].neurons_) {
        file >> neuron.bias_;
        for (auto& weight : neuron.weights_) {
          file >> weight;
        }
      }
    }
    file.close();
    return true;
  } else {
    return false;
  }
}

void GraphNetwork::InitFirstLayer(std::pair<Matrix, size_t> input) {
  answer_ = input.second;
  for (size_t k = 0; k < network_[0].neurons_.size(); ++k) {
    network_[0].neurons_[k].value_ = input.first(k, 0);
  }
}

void GraphNetwork::CheckAnswer() {
  size_t ind = 0;
  float max = network_.back().neurons_[0].value_;
  for (size_t j = 0; j < network_.back().neurons_.size(); j++) {
    if (j == answer_) {
      data_.mse += powf((1 - network_.back().neurons_[j].value_), 2);
    } else {
      data_.mse += powf((0 - network_.back().neurons_[j].value_), 2);
    }
    if (network_.back().neurons_[j].value_ >= 0.5) {
      j == answer_ ? TP_++ : FP_++;
    } else {
      j == answer_ ? FN_++ : TN_++;
    }
    if (max < network_.back().neurons_[j].value_) {
      max = network_.back().neurons_[j].value_;
      ind = j;
    }
  }
  data_.answer = 65 + ind;
}

}  // namespace s21
