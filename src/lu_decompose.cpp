/*============================================================================*/

#include <cstdint>
#include <tuple>
#include "matrix.hpp"

/*============================================================================*/
namespace task {
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

auto LU_decompose(Matrix& matrix) {
  Matrix lower(matrix.Size()), upper(matrix.Size());

  for (uint64_t i = 0; i < matrix.Size(); ++i) {
    
    for (uint64_t k = i; k < matrix.Size(); ++k) {  
      T sum = 0;
      for (uint64_t j = 0; j < i; ++j) {
        sum += lower.Get(i, j) * upper.Get(j, k);
      }

      upper.Get(i, k) = matrix.Get(i, k) - sum;
    }

    for (uint64_t k = i; k < matrix.Size(); ++k) {
      if (i == k) {
        lower.Get(i, i) = 1;
        continue;
      }

      T sum = 0;
      for (uint64_t j = 0; j < i; ++j) {
        sum += lower.Get(k, j) * upper.Get(j, i);
      }

      lower.Get(k, i) = (matrix.Get(k, i) - sum) / upper.Get(i, i);
    }
  }

  return std::make_tuple(lower, upper);
}

/*============================================================================*/
}
/*============================================================================*/
