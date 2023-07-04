//#ifndef CPP7_MLP_2_SRC_MODEL_MODEL_H_
//#define CPP7_MLP_2_SRC_MODEL_MODEL_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "fastmatrix.h"
namespace s21 {
class Reader {
 public:
  Reader() = default;
  ~Reader() = default;
  void ReadFile(const std::string& filename, char c);

 public:
  // TODO private
  std::vector<std::pair<Matrix, size_t>> train;
  std::vector<std::pair<Matrix, size_t>> test;
};
//    };
}  // namespace s21
