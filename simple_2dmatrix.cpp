#include <iostream>

int main() {
  int matrix[3][3] = {
  {1, 2, 3},
  {1, 2, 3},
  {1, 2, 3}
  };
  
  char answer;
  std::cout << "What do you want? "; 
  std::cin >> answer;
  switch(answer) {
    case 1:
  int x = 0, y = 0;
  while(matrix[x] > 0) {
    while(matrix[y] >0) {
      ++y;
      std::cout << matrix[x][y];
      }
    ++x;
    std::cout << matrix[x][y];
  }
};
