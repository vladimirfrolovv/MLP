#include "controller.h"

namespace s21 {

Controller* Controller::instance_ = nullptr;

Controller::Controller() { model_ = nullptr; }

Controller::~Controller() {
  if (model_) delete model_;
}

Controller* Controller::GetInstance() {
  if (!instance_) instance_ = new Controller;
  return instance_;
}

void Controller::InitNetwork(std::vector<size_t> config, bool is_graph) {
  if (!model_) {
    model_ = new Model;
    model_->ChoiceNetwork(is_graph, config);
  }
}

void Controller::Train(std::string filename) {
  data_ = model_->Train(filename);
}

void Controller::TrainWithCrossValidation(std::string filename, size_t kgroup) {
  data_ = model_->CrossValidation(filename, kgroup);
}

void Controller::Test(std::string filename, float share) {
  data_ = model_->Test(filename, share);
}
void Controller::SaveWeights(std::string filename) {
  model_->SaveWeights(filename);
}
bool Controller::LoadWeights(std::string filename, bool is_graph) {
  if (!model_) {
    model_ = new Model;
  }
  return model_->LoadWeights(filename, is_graph);
}

void Controller::TestOneLetter(std::vector<float> picture) {
  data_ = model_->TestOneLetter(picture);
}

void Controller::ResetTraining() {
  model_->~Model();
  model_ = nullptr;
  forMSEgraph.clear();
  data_.answer = {};
  data_.average_accuracy_ = 0;
  data_.f_measure = 0;
  data_.mse = 0;
  data_.precision = 0;
  data_.recall = 0;
}

const bool& Controller::GetIsTrained() { return networkIsTrained_; }
void Controller::SetIsTrained(bool value) { networkIsTrained_ = value; }

const std::vector<double>& Controller::GetMseForGraph() { return forMSEgraph; }
double Controller::GetAverageAccuracy() { return data_.average_accuracy_; }
double Controller::GetPrecisions() { return data_.precision; }
double Controller::GetRecalls() { return data_.recall; }
double Controller::GetFMeasures() { return data_.f_measure; }
char Controller::GetAnswer() { return data_.answer; }
double Controller::GetMse() { return data_.mse; }
bool Controller::GetTypeNetwork() { return isGraph_; }
void Controller::SetTypeNetwork(bool value) { isGraph_ = value; }

}  // namespace s21
