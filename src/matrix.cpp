#include "matrix.hpp"
#include <bits/stdint-uintn.h>
#include <cassert>
#include <ostream>
#include <vector>

namespace task {

Matrix::Matrix(size_t size) 
    : size_(size) {
  data_.resize(size_);
  for (auto& vector : data_) {
    vector.resize(size_);
  }
}

Matrix::Matrix(size_t size, std::vector<std::vector<T>> data) 
    : size_(size),
      data_(std::move(data)) {
}

T& Matrix::Get(uint64_t x, uint64_t y) {
  assert(x < size_ && y < size_);
  return data_[x][y];
}

size_t Matrix::Size() const {
  return size_;
}

void Matrix::Print(std::ostream& stream) const {
  for (size_t x = 0; x < size_; ++x) {
    for (size_t y = 0; y < size_; ++y) {
      stream << data_[x][y] << "\t";
    }
    stream << "\n";
  }
  stream << "\n";
}

/*============================================================================*/

MatrixView::MatrixView(Matrix& matrix, uint64_t x, uint64_t y, size_t size) 
    : base_(&matrix), offset_x_(x), offset_y_(y), size_(size) {
}

T& MatrixView::Get(uint64_t x, uint64_t y) {
  assert(x < size_ && y < size_);
  return base_->Get(offset_x_ + x, offset_y_ + y);
}

size_t MatrixView::Size() const {
  return size_;
}



}
