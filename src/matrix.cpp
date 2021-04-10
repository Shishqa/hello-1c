/*============================================================================*/

#include "matrix.hpp"

#include <cassert>
#include <istream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>

/*============================================================================*/
namespace task {
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Matrix::Matrix(size_t size) : size_(size) {
  data_.resize(size_);
  for (auto& vector : data_) {
    vector.resize(size_);
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Matrix::Matrix(size_t size, std::vector<std::vector<T>> data)
    : size_(size), data_(std::move(data)) {
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Matrix::Matrix(std::istream& stream) {
  stream >> size_;
  data_.resize(size_);
  for (size_t i = 0; i < size_; ++i) {
    data_[i].resize(size_);
    for (size_t j = 0; j < size_; ++j) {
      stream >> data_[i][j];
    }
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

T& Matrix::Get(uint64_t x, uint64_t y) {
  assert(x < size_ && y < size_);
  return data_[x][y];
}

const T& Matrix::Get(uint64_t x, uint64_t y) const {
  assert(x < size_ && y < size_);
  return data_[x][y];
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

size_t Matrix::Size() const {
  return size_;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Matrix::Print(std::ostream& stream) const {
  for (size_t y = 0; y < size_; ++y) {
    stream << "| ";
    for (size_t x = 0; x < size_; ++x) {
      stream << data_[y][x] << " ";
    }
    stream << "|\n";
  }
  stream << "\n";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

T Matrix::Determinant() {
  static constexpr double EPS = 1E-9;

  T det = 1;
  for (size_t i = 0; i < Size(); ++i) {
    size_t k = i;

    for (size_t j = i + 1; j < Size(); ++j) {
      if (std::abs(Get(j, i)) > std::abs(Get(k, i))) {
        k = j;
      }
    }

    if (std::abs(Get(k, i)) < EPS) {
      det = 0;
      break;
    }

    swap(data_[i], data_[k]);

    if (i != k) {
      det = -det;
    }
    det *= Get(i, i);

    for (size_t j = i + 1; j < Size(); ++j) {
      Get(i, j) /= Get(i, i);
    }

    for (size_t j = 0; j < Size(); ++j) {
      if (j != i && std::abs(Get(j, i)) > EPS) {
        for (size_t k = i + 1; k < Size(); ++k) {
          Get(j, k) -= Get(i, k) * Get(j, i);
        }
      }
    }
  }

  return det;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Matrix::FlipSubmatrix(bool main, uint64_t x, uint64_t y, size_t size) {
  for (uint64_t i = 0; i < size; ++i) {
    for (uint64_t j = 0; j < (main ? i : size - i - 1); ++j) {
      std::swap(
          data_[x + i][y + j],
          data_[x + (main ? j : size - 1 - j)][y + (main ? i : size - 1 - i)]);
    }
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
}  // namespace task
/*============================================================================*/

