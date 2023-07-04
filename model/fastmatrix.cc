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
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) = other(i, j);
    }
  }
}

int Matrix::GetRows() const { return rows_; }

void Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument("Incorrect value of rows");
  }
  if (rows != rows_) {
    Matrix tmp(*this);
    this->Remove_matrix();
    rows_ = rows;
    cols_ = tmp.cols_;
    this->Allocate_matrix();
    for (int i = 0; i < std::min(tmp.rows_, rows); i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        (*this)(i, j) = tmp(i, j);
      }
    }
  }
}

Matrix::Matrix(Matrix &&other)

    noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

Matrix::~Matrix() { this->Remove_matrix(); }

void Matrix::Allocate_matrix() {
//    matrix_ = new float[rows_ * cols_]();
  matrix_ = new float *[rows_]();
  matrix_[0] = new float[rows_ * cols_]();
  for (auto i = 1; i < rows_; ++i) {
    matrix_[i] = matrix_[i - 1] + cols_;
  }
}

void Matrix::Remove_matrix() {
  if (matrix_ != nullptr) {
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

int Matrix::GetCols() const { return cols_; }

void Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::invalid_argument("Incorrect value of cols");
  }
  if (cols != cols_) {
    Matrix tmp(*this);
    this->Remove_matrix();
    cols_ = cols;
    rows_ = tmp.rows_;
    this->Allocate_matrix();
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < std::min(tmp.cols_, cols); j++) {
        (*this)(i, j) = tmp(i, j);
      }
    }
  }
}

float **Matrix::GetMatrix() const { return matrix_; }

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
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        (*this)(i, j) = other(i, j);
      }
    }
  }
  return *this;
}

Matrix &Matrix::operator=(Matrix &&other)

    noexcept {
  if (this != &other) {
    this->

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

float &Matrix::operator()(int rows, int cols) {
  if (rows > rows_ || rows < 0 || cols > cols_ || cols < 0) {
    throw std::out_of_range("Invalid size of matrix");
  }
  return matrix_[rows][cols];
//    return matrix_[rows * cols_ + cols];
}

float &Matrix::operator()(int rows, int cols) const {
  if (rows > rows_ || rows < 0 || cols > cols_ || cols < 0) {
    throw std::out_of_range("Invalid size of matrix");
  }
  return matrix_[rows][cols];
//    return matrix_[rows * cols_ + cols];
}

void Matrix::SumMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void Matrix::SubMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void Matrix::MulNumber(const float num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void Matrix::MulMatrix(const Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Invalid size of matrix");
  }
  Matrix res(rows_, other.cols_);
  //        for (int i = 0; i < rows_; i++) {
  //            for (int j = 0; j < other.cols_; j++) {
  //                for (int k = 0; k < cols_; k++) {
  //                    res(i,j) += this->operator()(i,k) * other(k,j);
  //                }
  //            }
  //        }
  //  for (int i = 0; i < rows_; i++) {
  //    float *c = res.matrix_ + i * other.cols_;
  //    for (int k = 0; k < cols_; k++) {
  //      const float *b = other.matrix_ + k * other.cols_;
  //      float a = this->matrix_[i * cols_ + k];
  //      for (int j = 0; j < other.cols_; j++) {
  //        c[j] += a * b[j];
  //      }
  //    }
  //  }
//     const std::size_t d = GetCols() / 2;
//         std::vector<float> rowFactor(res.GetRows());
//         std::vector<float> colsFactor(other.GetCols());
//         for (std::size_t i = 0; i < rowFactor.size(); ++i) {
//             rowFactor[i] = matrix_[i * GetCols()] * matrix_[i * GetCols()
//             +1]; for (std::size_t j = 1; j < d; ++j) {
//                 rowFactor[i] += matrix_[i * GetCols() + (2 * j)] * matrix_[i
//                 * GetCols() + (2 * j + 1)];
//             }
//         }
//         for (std::size_t i = 0; i < colsFactor.size(); ++i) {
//             colsFactor[i] = other.matrix_[ i] * other.matrix_[other.GetCols()
//             * 1 + i]; for (std::size_t j = 1; j < d; ++j) {
//                 colsFactor[i] += other.matrix_[other.GetCols() * (2 * j) + i]
//                 * other.matrix_[other.GetCols() * (2 * j + 1) + i];
//             }
//         }
//
//
//         for (std::size_t i = 0; i < res.GetRows(); ++i) {
//             for (std::size_t j = 0; j < res.GetCols(); ++j) {
//                 res(i, j) = -rowFactor[i] - colsFactor[j];
//                 for (std::size_t k = 0; k < d; ++k) {
//                     res(i, j) += (matrix_[i * GetCols() + (2 * k)] +
//                     other.matrix_[other.GetCols() * (2 * k + 1 )+ j]) *
//                                     (matrix_[i * GetCols() + (2 * k + 1)] +
//                                     other(2 * k, j));
//                 }
//             }
//         }
//
//         if (res.GetCols() % 2 == 1) {
//             for (std::size_t i = 0; i < res.GetRows(); ++i) {
//                 for (std::size_t j = 0; j < res.GetCols(); ++j) {
//                     res(i, j) += matrix_[i * GetCols() + (res.GetCols() - 1)]
//                     * other.matrix_[other.GetCols() * (res.GetCols() - 1) +
//                     j];
//                 }
//             }
//         }
  const std::size_t d = GetCols() / 2;
  std::vector<float> rowFactor(res.GetRows());
  std::vector<float> colsFactor(other.GetCols());
  for (std::size_t i = 0; i < rowFactor.size(); ++i) {
    rowFactor[i] = matrix_[i][0] * matrix_[i][1];
    for (std::size_t j = 1; j < d; ++j) {
      rowFactor[i] += matrix_[i][2 * j] * matrix_[i][2 * j + 1];
    }
  }
  for (std::size_t i = 0; i < colsFactor.size(); ++i) {
    colsFactor[i] = other(0, i) * other(1, i);
    for (std::size_t j = 1; j < d; ++j) {
      colsFactor[i] += other(2 * j, i) * other(2 * j + 1, i);
    }
  }

  for (std::size_t i = 0; i < res.GetRows(); ++i) {
    for (std::size_t j = 0; j < res.GetCols(); ++j) {
      res(i, j) = -rowFactor[i] - colsFactor[j];
      for (std::size_t k = 0; k < d; ++k) {
        res(i, j) += (matrix_[i][2 * k] + other(2 * k + 1, j)) *
                     (matrix_[i][2 * k + 1] + other(2 * k, j));
      }
    }
  }

  if (res.GetCols() % 2 == 1) {
    for (std::size_t i = 0; i < res.GetRows(); ++i) {
      for (std::size_t j = 0; j < res.GetCols(); ++j) {
        res(i, j) +=
            matrix_[i][res.GetCols() - 1] * other(res.GetCols() - 1, j);
      }
    }
  }

  *this = std::move(res);
}

Matrix Matrix::Transpose() const {
  Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res(j, i) = (*this)(i, j);
    }
  }
  return res;
}

}  // namespace s21