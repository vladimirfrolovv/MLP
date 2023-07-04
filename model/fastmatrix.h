#include <cmath>
#include <iostream>
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

  float &operator()(int rows, int cols);

  float &operator()(int rows, int cols) const;

  friend Matrix operator*(float num, const Matrix &other);

  friend Matrix operator*(const Matrix &other, float num);

  int GetRows() const;

  void SetRows(int rows);

  int GetCols() const;

  void SetCols(int cols);

  float **GetMatrix() const;

  void SumMatrix(const Matrix &other);

  void SubMatrix(const Matrix &other);

  void MulNumber(float num);

  void MulMatrix(const Matrix &other);
  Matrix Transpose() const;

 private:
  int rows_, cols_;

  float **matrix_{};

  void Allocate_matrix();

  void Remove_matrix();
};
}  // namespace s21