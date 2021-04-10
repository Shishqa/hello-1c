# Hello, 1C

## The task

"Игра в определитель"

На вход программе подаётся квадратная матрица. Необходимо изменить её так, чтобы модуль определителя оказался максимально возможным. 
Доступное действие только одно: выбрать любую сплошную квадратную подматрицу (то есть квадрат от a[i][j] до a[k][s], где i < k, j < s, k - i == s - j) данной и отразить её относительно любой из диагоналей.
Необходимо реализовать программу, решающую эту задачу и выводящую итоговый вид матрицы, значение определителя и минимальное количество ходов, требуемых для достижения этого вида.

## Prerequisites

- C++ compiler (gcc, clang, ...)
- CMake

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running

```bash
cd <repo-root>
./bin/hello-1c <FILE WITH MATRIX>
```

## Examples

```bash
$ ./bin/hello-1c ./examples/MATRIX3
Got Matrix:
| 1 0 0 |
| 0 1 0 |
| 1 0 0 |

Best Determinant is -1


$ ./bin/hello-1c ./examples/MATRIX3
Got Matrix:
| 1 2 3 4 |
| 0 0 0 1 |
| 1 3 4 0 |
| 2 2 2 2 |

Best Determinant is 160


$ ./bin/hello-1c ./examples/MATRIX3
Got Matrix:
| 1 -1 1 |
| -1 1 -1 |
| 1 -1 1 |

Best Determinant is 0
```
