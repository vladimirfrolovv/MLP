#ifndef CPP7_MLP_2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP7_MLP_2_SRC_CONTROLLER_CONTROLLER_H_

#define GRAPH true
#define MATRIX false

#include "../Model/model.h"
#include "../Model/struct_output_data.h"

namespace s21 {
class Controller {
 public:
  ~Controller();
  static Controller* GetInstance();
  void InitNetwork(std::vector<size_t> config, bool is_graph);

  void Train(std::string filename);
  void TrainWithCrossValidation(std::string filename, size_t kgroup);

  void Test(std::string filename, float share);
  void SaveWeights(std::string filename);
  bool LoadWeights(std::string filename, bool is_graph);
  void SetIsTrained(bool value);
  const bool& GetIsTrained();
  void TestOneLetter(std::vector<float> picture);
  const std::vector<double>& GetMseForGraph();

  double GetAverageAccuracy();
  double GetPrecisions();
  double GetRecalls();
  double GetFMeasures();

  char GetAnswer();
  double GetMse();

  bool GetTypeNetwork();
  void SetTypeNetwork(bool value);

  void ResetTraining();

  std::vector<double> forMSEgraph{};

 private:
  output_data_ data_;
  Controller();
  Model* model_;
  static Controller* instance_;
  bool networkIsTrained_ = false;
  bool isGraph_ = GRAPH;
};
}  // namespace s21

#endif  // CPP7_MLP_2_SRC_CONTROLLER_CONTROLLER_H_
