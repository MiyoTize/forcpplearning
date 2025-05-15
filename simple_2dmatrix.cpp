#include <iostream>

int main() {
  int matrix[5][5] = {
  {1, 2, 3, 4, 5},
  {1, 2, 3, 4, 5},
  {1, 2, 3, 4, 5},
  {1, 2, 3, 4, 5},
  {1, 2, 3, 4, 5}
  };

  int x, y;
  char answer;

  std::cour << "Heyo! Here Miyo!\n"
  std::cout << "What do you want? "; 
  std::cin >> answer;
  switch(answer) {
    case 1:
      while(matrix[x] < 4) {
        while(matrix[y] < 4) {
          ++y;
          std::cout << matrix[x][y] << " ";
          }
        ++x;
        std::cout << matrix[x][y] << " ";
        }
    
    case 2:
      std::cout << "Please, write a place of mAssive: ";
      std::cin >> x, y;
      std::cout << "Result: " << matrix[x][y];
      return 0;
    
    case 3:
      char xory;
      std::cout << "Please, write x or y of mAssive (1 or 2): ";
      switch(xory) {
        case 1:
          std::cout << "Please, write x here: ";
          std::cin >> x;
          while(matrix[y] < 4) {
            std::cout << matrix[x][y] << " ";
            ++y;
          }
        case 2:
          std::cout << "Please, write y here: ";
          std::cin >> y;
          while(matrix[x] < 4) {
            std::cout << matrix[x][y] << " ";
            ++x;
          }
  }
  std::cout << "Bye!";
  return 0;
}
