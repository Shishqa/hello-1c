/*============================================================================*/

#include <bits/stdint-uintn.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#include "lu_decompose.hpp"
#include "matrix.hpp"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
using namespace task;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

auto GetWhitesAndBlacks(Matrix& m) {
  std::vector<T> whites, blacks;

  for (size_t i = 0; i < m.Size(); ++i) {
    for (size_t j = 0; j < m.Size(); ++j) {
      if ((i + j) % 2) {
        whites.push_back(m.Get(i, j));
      } else {
        blacks.push_back(m.Get(i, j));
      }
    }
  }

  return std::make_tuple(whites, blacks);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

T FindBestDeterminant(Matrix& m) {
  double best_det = 0;
  Matrix tmp(m.Size());

  auto [whites, blacks] = GetWhitesAndBlacks(m);

  std::sort(whites.begin(), whites.end());
  std::sort(blacks.begin(), blacks.end());

  do {
    do {
      uint64_t white_idx = 0;
      uint64_t black_idx = 0;

      for (size_t i = 0; i < m.Size(); ++i) {
        for (size_t j = 0; j < m.Size(); ++j) {
          if ((i + j) % 2) {
            tmp.Get(i, j) = whites[white_idx++];
          } else {
            tmp.Get(i, j) = blacks[black_idx++];
          }
        }
      }

      T curr_det = tmp.Determinant();
      if (std::abs(curr_det) > std::abs(best_det)) {
        best_det = curr_det;
      }

    } while (std::next_permutation(blacks.begin(), blacks.end()));
  } while (std::next_permutation(whites.begin(), whites.end()));

  return best_det;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <file with matrix>\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cout << "cannot open file " << argv[1];
    return 1;
  }
   
  Matrix m(file); 

  std::cout << "Got Matrix:\n";
  m.Print(std::cout);

  std::cout << "Best Determinant is " << FindBestDeterminant(m) << "\n";

  return 0;
}

/*============================================================================*/
