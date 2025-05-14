#include <iostream>

int main() {
  int matrix[3][3] = {
  {1, 2, 3},
  {1, 2, 3},
  {1, 2, 3}
  };
  
  int x, y;
  std::cout << "Please, write x and y of matrix: ";
  std::cin >> x, y;
  std::cout << "\nResult: " << matrix[x][y];
};
	
