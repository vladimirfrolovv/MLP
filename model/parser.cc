#include "parser.h"
namespace s21 {
void Reader::ReadFile(const std::string& filename, char c) {
  std::ifstream file(filename, std::ios::ate);
  if (file) {
    int idx_mat = 0;
    if (c == 't') {
      train.reserve(file.tellg());
      file.seekg(0, std::ios::beg);
      float value = 0;
      std::string line{};
      std::string item{};
      idx_mat = 0;
      train.emplace_back(Matrix(784, 1), 1);
      while (getline(file, line)) {
        std::stringstream ss(line);
        while (getline(ss, item, ',')) {
          if (idx_mat < 784) {
            if (idx_mat == 0) {
              train.back().second = stoi(item);
            } else {
              train.back().first(idx_mat, 0) = stof(item) / 255.f;
            }
            idx_mat++;
          } else {
            train.emplace_back(Matrix(784, 1), 1);
            idx_mat = 0;
          }
        }
      }
    } else {
      idx_mat = 0;
      test.reserve(file.tellg());
      file.seekg(0, std::ios::beg);
      float value = 0;
      std::string line{};
      std::string item{};
      test.emplace_back(Matrix(784, 1), 1);
      while (getline(file, line)) {
        std::stringstream ss(line);
        while (getline(ss, item, ',')) {
          if (idx_mat < 784) {
            if (idx_mat == 0) {
              test.back().second = stoi(item);
            } else {
              test.back().first(idx_mat, 0) = stof(item) / 255.f;
            }
            idx_mat++;
          } else {
            test.emplace_back(Matrix(784, 1), 1);
            idx_mat = 0;
          }
        }
      }
    }
    file.close();
  } else {
    std::cout << "No such file";
  }
}
}  // namespace s21
