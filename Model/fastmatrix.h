#ifndef CPP7_MLP_2_SRC_MODEL_FASTMATRIX_H_
#define CPP7_MLP_2_SRC_MODEL_FASTMATRIX_H_
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
namespace s21 {

class Matrix {
 public:
  Matrix();

  Matrix(int rows, int cols);

  Matrix(const Matrix &other);

  Matrix(Matrix &&other) noexcept;

  ~Matrix();

  Matrix &operator=(const Matrix &other);

  Matrix &operator=(Matrix &&other) noexcept;

  Matrix &operator+=(const Matrix &other);

  Matrix operator+(const Matrix &other);

  Matrix &operator-=(const Matrix &other);

  Matrix operator-(const Matrix &other);

  Matrix &operator*=(float num);

  Matrix &operator*=(const Matrix &other);

  Matrix operator*(const Matrix &other);

  float &operator()(size_t rows, size_t cols) const;

  friend Matrix operator*(float num, const Matrix &other);

  friend Matrix operator*(const Matrix &other, float num);

  [[nodiscard]] size_t GetRows() const;

  void SetRows(size_t rows);

  [[nodiscard]] size_t GetCols() const;

  void SetCols(size_t cols);

  void SumMatrix(const Matrix &other);

  void SubMatrix(const Matrix &other);

  void MulNumber(float num);

  void MulMatrix(const Matrix &other);

  [[nodiscard]] Matrix Transpose() const;

 private:
  size_t rows_, cols_;

  float *matrix_{};

  void Allocate_matrix();

  void Remove_matrix();
};
}  // namespace s21

#endif  // CPP7_MLP_2_SRC_MODEL_FASTMATRIX_H_