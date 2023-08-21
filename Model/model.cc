#include "model.h"

namespace s21 {

void Model::ChoiceNetwork(bool is_graph, std::vector<size_t> config) {
  if (is_graph) {
    delete network_;
    network_ = new GraphNetwork(config);
  } else {
    delete network_;
    network_ = new MatrixNetwork(config);
  }
}

output_data_ Model::Train(std::string filename) {
  if (train_sample_.empty()) {
    train_sample_ = reader_.ReadFile(filename);
  }
  size_t size = train_sample_.size();
  for (size_t i = 0; i < size; ++i) {
    network_->InitFirstLayer(train_sample_[i]);
    network_->ForwardFeed();
    network_->BackPropagation();
  }
  float tmp_l_r = network_->GetLearningRate() * 0.7f;
  network_->GetLearningRate() = tmp_l_r;

  return network_->GetData(size);
  ;
}

output_data_ Model::Test(std::string testfile, float share) {
  if (test_sample_.empty()) {
    test_sample_ = reader_.ReadFile(testfile);
  }
  size_t size = static_cast<float>(test_sample_.size()) * share;
  network_->ClearMse().mse = 0;
  for (size_t i = 0; i < size; ++i) {
    network_->InitFirstLayer(test_sample_[i]);
    network_->ForwardFeed();
    network_->CheckAnswer();
  }
  return network_->GetData(size);
}

output_data_ Model::TestOneLetter(std::vector<float> picture) {
  Matrix tmp(picture.size() - 1, 1);
  network_->ClearMse().mse = 0;
  for (size_t j = 0; j < picture.size() - 1; ++j) {
    tmp(j, 0) = picture[j];
  }
  std::pair<Matrix, size_t> s;
  s.first = tmp;
  s.second = 0;
  network_->InitFirstLayer(s);
  network_->ForwardFeed();
  network_->CheckAnswer();
  return network_->GetData(1);
}

void Model::SaveWeights(std::string filename) {
  network_->SaveWeights(filename);
}

bool Model::LoadWeights(std::string filename, bool is_graph) {
  std::vector<size_t> config = {784, 64, 64, 26};
  if (is_graph) {
    delete network_;
    network_ = new GraphNetwork(config);
  } else {
    delete network_;
    network_ = new MatrixNetwork(config);
  }
  return network_->LoadWeights(filename);
}

output_data_ Model::CrossValidation(std::string filename, size_t k_group) {
  if (train_sample_.empty()) {
    train_sample_ = reader_.ReadFile(filename);
  }
  size_t size = train_sample_.size();
  size_t size_test = size / k_group;
  size_t start_test = 0;
  size_t end_test = size_test;
  output_data_ res;
  std::vector<std::pair<Matrix, size_t>> test_tmp;
  test_tmp.reserve(size_test);
  for (size_t j = 0; j < k_group; ++j) {
    for (size_t i = 0; i < size; ++i) {
      if (i >= start_test && i <= end_test) {
        test_tmp.push_back(train_sample_[i]);
      } else {
        network_->InitFirstLayer(train_sample_[i]);
        network_->ForwardFeed();
        network_->BackPropagation();
      }
    }
    for (auto& elem : test_tmp) {
      network_->InitFirstLayer(elem);
      network_->ForwardFeed();
      network_->CheckAnswer();
    }
    test_tmp.clear();
    start_test += size_test;
    end_test += size_test;
    res = network_->GetData(size_test);
  }
  return res;
}
}  // namespace s21
