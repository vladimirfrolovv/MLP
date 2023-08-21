#include "neuralnetwork.h"

output_data_ s21::NeuralNetwork::GetData(size_t size) {
  data_.average_accuracy_ = (TP_ + TN_) / (TP_ + TN_ + FP_ + FN_);
  data_.precision = TP_ / (TP_ + FP_);
  data_.recall = TP_ / (TP_ + FN_);
  data_.f_measure =
      (2.0 * data_.precision * data_.recall) / (data_.precision + data_.recall);
  data_.mse /= size;
  return data_;
}

output_data_ &s21::NeuralNetwork::ClearMse() { return data_; }

float &s21::NeuralNetwork::GetLearningRate() { return learning_rate_; }
