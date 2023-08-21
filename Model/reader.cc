#include "reader.h"
namespace s21 {
std::vector<std::pair<Matrix, size_t>> Reader::ReadFile(std::string filename) {
  std::vector<std::pair<Matrix, size_t>> sample_;
  std::ifstream file(filename, std::ios::ate);
  if (file) {
    int idx_mat = 0;
    sample_.reserve(file.tellg() / 40);
    sample_.emplace_back(Matrix(size_input_layer_, 1), 1);
    file.seekg(0, std::ios::beg);
    std::string line{};
    std::string item{};
    idx_mat = 0;
    while (getline(file, line)) {
      std::stringstream ss(line);
      while (getline(ss, item, ',')) {
        if (idx_mat < size_input_layer_) {
          if (idx_mat == 0) {
            sample_.back().second = stoi(item) - 1;
          } else {
            sample_.back().first(idx_mat, 0) = stof(item) / 255.f;
          }
          idx_mat++;
        } else {
          sample_.emplace_back(Matrix(size_input_layer_, 1), 1);
          idx_mat = 0;
        }
      }
    }
    file.close();
  } else {
    std::cout << "No such file";
  }
  return sample_;
}
}  // namespace s21
