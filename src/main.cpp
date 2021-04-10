/*============================================================================*/

#include <iostream>

#include "lu_decompose.hpp"
#include "matrix.hpp"

using namespace task;

int main(int /*argc*/, char* /*argv*/[]) {

  Matrix m(3, {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}}); 

  Matrix l(3), u(3);

  LU_decompose(m, l, u);  

  m.Print(std::cout);
  l.Print(std::cout);
  u.Print(std::cout);

  return 0;
}
