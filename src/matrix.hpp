/*============================================================================*/
#ifndef _MATRIX_HPP
#define _MATRIX_HPP
/*============================================================================*/

#include <bits/stdint-uintn.h>
#include <istream>
#include <ostream>
#include <vector>
#include <cstdint>

#include <fstream>

/*============================================================================*/
namespace task {
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

using T = double;

class Matrix {
 public:
  Matrix(size_t size, std::vector<std::vector<T>> data);

  Matrix(size_t size);

  Matrix(std::istream& stream);

  T& Get(uint64_t x, uint64_t y);

  const T& Get(uint64_t x, uint64_t y) const;

  void FlipSubmatrix(bool main, uint64_t x, uint64_t y, size_t size);

  size_t Size() const;

  T Determinant();

  void Print(std::ostream& stream) const;

 private:
  size_t size_;
  std::vector<std::vector<T>> data_;
};

/*============================================================================*/
}  // namespace task
/*============================================================================*/

#endif /* ifndef _MATRIX_HPP */
