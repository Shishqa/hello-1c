#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <bits/stdint-uintn.h>
#include <ostream>
#include <vector>
#include <cstdint>

#include <fstream>

namespace task {

using T = double;

class MatrixView;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class MatrixBase {
 public:
  virtual size_t Size() const = 0;

  virtual T& Get(uint64_t x, uint64_t y) = 0;
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class Matrix : public MatrixBase {
 public:
  Matrix(size_t size, std::vector<std::vector<T>> data);

  Matrix(size_t size);

  T& Get(uint64_t x, uint64_t y) override;

  size_t Size() const override;

  void Print(std::ostream& stream) const;

 private:
  size_t size_;
  std::vector<std::vector<T>> data_;
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

class MatrixView : public MatrixBase {
 public:
  MatrixView(Matrix& matrix, uint64_t x, uint64_t y, size_t size);

  T& Get(uint64_t x, uint64_t y) override;

  size_t Size() const override;

 private:
  Matrix* base_;
  uint64_t offset_x_;
  uint64_t offset_y_;
  size_t size_;
};

/*============================================================================*/
}  // namespace task
/*============================================================================*/

#endif /* ifndef _MATRIX_HPP */
