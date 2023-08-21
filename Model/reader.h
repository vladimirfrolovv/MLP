#ifndef CPP7_MLP_2_SRC_MODEL_READER_H_
#define CPP7_MLP_2_SRC_MODEL_READER_H_
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "fastmatrix.h"
namespace s21 {
class Reader {
 public:
  std::vector<std::pair<Matrix, size_t>> ReadFile(std::string filename);

 private:
  int size_input_layer_ = 784;
};
}  // namespace s21
#endif  // CPP7_MLP_2_SRC_MODEL_READER_H_