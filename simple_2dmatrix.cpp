#include <iostream>

int main() {
  int matrix[3][3] = {
  {1, 2, 3},
  {1, 2, 3},
  {1, 2, 3}
  };
  
  int x = 0, y = 0;
  while(matrix[x] > 0) {
    while(matrix[y] >0) {
      ++y;
      std::cout << matrix[x][y];
      };
    ++x;
    std::cout << matrix[x][y];
  };
};
