#include "model.h"

int main() {
  auto *nn = new s21::NeuralNetwork;
  std::vector<s21::Matrix> s;
  std::vector<int> size = {784, 64, 64, 26};
  nn->InitLayers(4, size);

  //      /Users/ikudr/S21/C++projects/MLP_new_ui/emnist-letters
  /// Users/fixierad/Projects/CPP7_MLP-2/srcData/
  nn->Train(
      "/Users/fixierad/Projects/CPP7_MLP-2/src/Data/emnist-letters-train.csv",
      1);
  nn->Test(
      "/Users/fixierad/Projects/CPP7_MLP-2/src/Data/"
      "emnist-letters-test.csv");
  return 0;
}
// const std::size_t d = GetCols() / 2;
//     std::vector<float> rowFactor(res.GetRows());
//     std::vector<float> colsFactor(other.GetCols());
//     for (std::size_t i = 0; i < rowFactor.size(); ++i) {
//         rowFactor[i] = matrix_[i * GetCols()] * matrix_[i * GetCols() +1];
//         for (std::size_t j = 1; j < d; ++j) {
//             rowFactor[i] += matrix_[i * GetCols() + (2 * j)] * matrix_[i *
//             GetCols() + (2 * j + 1)];
//         }
//     }
//     for (std::size_t i = 0; i < colsFactor.size(); ++i) {
//         colsFactor[i] = other(0, i) * other(1, i);
//         for (std::size_t j = 1; j < d; ++j) {
//             colsFactor[i] += other(2 * j, i) * other(2 * j + 1, i);
//         }
//     }
//
//
//     for (std::size_t i = 0; i < res.GetRows(); ++i) {
//         for (std::size_t j = 0; j < res.GetCols(); ++j) {
//             res(i, j) = -rowFactor[i] - colsFactor[j];
//             for (std::size_t k = 0; k < d; ++k) {
//                 res(i, j) += (matrix_[i * GetCols() + (2 * k)] + other(2 * k
//                 + 1, j)) *
//                                 (matrix_[i * GetCols() + (2 * k + 1)] +
//                                 other(2 * k, j));
//             }
//         }
//     }
//
//     if (res.GetCols() % 2 == 1) {
//         for (std::size_t i = 0; i < res.GetRows(); ++i) {
//             for (std::size_t j = 0; j < res.GetCols(); ++j) {
//                 res(i, j) += matrix_[i * GetCols() + (res.GetCols() - 1)] *
//                 other(res.GetCols() - 1, j);
//             }
//         }
//     }
//
