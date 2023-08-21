#include "fastmatrix.h"
namespace s21 {

Matrix::Matrix() : rows_(3), cols_(3) { Allocate_matrix(); }

Matrix::Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Incorrect size for matrix");
  } else {
    rows_ = rows;
    cols_ = cols;
    Allocate_matrix();
  }
}

Matrix::Matrix(const Matrix &other) {
  if (other.rows_ <= 0 || other.cols_ <= 0) {
    throw std::out_of_range("Incorrect size for matrix");
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->Allocate_matrix();
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) = other(i, j);
    }
  }
}

size_t Matrix::GetRows() const { return rows_; }

void Matrix::SetRows(size_t rows) {
  if (rows < 1) {
    throw std::invalid_argument("Incorrect value of rows");
  }
  if (rows != rows_) {
    Matrix tmp(*this);
    this->Remove_matrix();
    rows_ = rows;
    cols_ = tmp.cols_;
    this->Allocate_matrix();
    for (size_t i = 0; i < std::min(tmp.rows_, rows); i++) {
      for (size_t j = 0; j < tmp.cols_; j++) {
        (*this)(i, j) = tmp(i, j);
      }
    }
  }
}

Matrix::Matrix(Matrix &&other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

Matrix::~Matrix() { this->Remove_matrix(); }

void Matrix::Allocate_matrix() { matrix_ = new float[rows_ * cols_](); }

void Matrix::Remove_matrix() {
  if (matrix_ != nullptr) {
    delete[] matrix_;

    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

size_t Matrix::GetCols() const { return cols_; }

void Matrix::SetCols(size_t cols) {
  if (cols < 1) {
    throw std::invalid_argument("Incorrect value of cols");
  }
  if (cols != cols_) {
    Matrix tmp(*this);
    this->Remove_matrix();
    cols_ = cols;
    rows_ = tmp.rows_;
    this->Allocate_matrix();
    for (size_t i = 0; i < tmp.rows_; i++) {
      for (size_t j = 0; j < std::min(tmp.cols_, cols); j++) {
        (*this)(i, j) = tmp(i, j);
      }
    }
  }
}

Matrix &Matrix::operator=(const Matrix &other) {
  if (this != &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      if (matrix_ != nullptr) {
        this->Remove_matrix();
      }
      rows_ = other.rows_;
      cols_ = other.cols_;
      this->Allocate_matrix();
    }
    for (size_t i = 0; i < rows_; i++) {
      for (size_t j = 0; j < cols_; j++) {
        (*this)(i, j) = other(i, j);
      }
    }
  }
  return *this;
}

Matrix &Matrix::operator=(Matrix &&other)

    noexcept {
  if (this != &other) {
    Remove_matrix();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

Matrix &Matrix::operator+=(const Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

Matrix Matrix::operator+(const Matrix &other) {
  Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

Matrix &Matrix::operator-=(const Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

Matrix Matrix::operator-(const Matrix &other) {
  Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

Matrix &Matrix::operator*=(const float num) {
  this->MulNumber(num);
  return *this;
}

Matrix operator*(float num, const Matrix &other) {
  Matrix res(other);
  res.MulNumber(num);
  return res;
}

Matrix operator*(const Matrix &other, float num) {
  Matrix res(other);
  res.MulNumber(num);
  return res;
}

Matrix &Matrix::operator*=(const Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

Matrix Matrix::operator*(const Matrix &other) {
  Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

float &Matrix::operator()(size_t rows, size_t cols) const {
  if (rows >= rows_ || cols >= cols_) {
    throw std::out_of_range("Invalid size of matrix");
  }
  return matrix_[rows * cols_ + cols];
}

void Matrix::SumMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void Matrix::SubMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void Matrix::MulNumber(const float num) {
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void Matrix::MulMatrix(const Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  Matrix res(rows_, other.cols_);

  const std::size_t d = cols_ / 2;
  std::vector<float> rowFactor(rows_);
  std::vector<float> colsFactor(other.cols_);
  for (std::size_t i = 0; i < rows_; ++i) {
    float sum = matrix_[i * cols_] * matrix_[i * cols_ + 1];
    for (std::size_t j = 1; j < d; ++j) {
      const std::size_t tmp = 2 * j;
      sum += matrix_[i * cols_ + tmp] * matrix_[i * cols_ + tmp + 1];
    }
    rowFactor[i] = sum;
  }
  for (std::size_t i = 0; i < other.cols_; ++i) {
    float sum = other.matrix_[i] * other.matrix_[other.cols_ * 1 + i];
    for (std::size_t j = 1; j < d; ++j) {
      const std::size_t tmp = 2 * j;
      sum += other.matrix_[other.cols_ * tmp + i] *
             other.matrix_[other.cols_ * (tmp + 1) + i];
    }
    colsFactor[i] = sum;
  }

  for (std::size_t i = 0; i < rows_; ++i) {
    for (std::size_t j = 0; j < other.cols_; ++j) {
      float sum = -rowFactor[i] - colsFactor[j];
      for (std::size_t k = 0; k < d; ++k) {
        const std::size_t tmp = 2 * k;
        sum += (matrix_[i * cols_ + tmp] +
                other.matrix_[other.cols_ * (tmp + 1) + j]) *
               (matrix_[i * cols_ + (tmp + 1)] + other(tmp, j));
      }
      res(i, j) = sum;
    }
  }

  if (cols_ % 2 == 1) {
    for (std::size_t i = 0; i < rows_; ++i) {
      for (std::size_t j = 0; j < other.cols_; ++j) {
        res(i, j) += matrix_[i * cols_ + (cols_ - 1)] *
                     other.matrix_[other.cols_ * (res.cols_ - 1) + j];
      }
    }
  }

  *this = std::move(res);
}

Matrix Matrix::Transpose() const {
  Matrix res(cols_, rows_);
  for (size_t i = 0; i < rows_; i++) {
    for (size_t j = 0; j < cols_; j++) {
      res(j, i) = (*this)(i, j);
    }
  }
  return res;
}

}  // namespace s21