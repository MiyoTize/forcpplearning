
// WHY THIS CODE DOESNT WORK :(((((((((((((((

#include <iostream>

int matrix() {
  std::cout << "Heyo! Here Miyo!\n";
  std::cout << "What do you want?\n(1) - print one number of massive\n(2) - print one string\n(3) - print all strings\n";
	std::cout << "Please, write here: ";

  int choice;
  std::cin >> choice;
  int x{};
  int y{};
  switch(choice) {
    case 1: // printed only one number
      std::cout << "Please, write a place of mAssive: ";
      std::cin >> x, y;
      std::cout << "Result: " << matrix[x][y];
      return 0;
    
    case 2: // printed string ( x or y )
      std::cout << "Please, write x or y of massive (1 or 2): ";
			char xory; // x or y
			std::cin >> xory;
      switch(xory) {
        case 1: // for x
          std::cout << "Please, write x here: ";
          std::cin >> x;
          y = 0;
          while(y <= 4) {
            std::cout << matrix[x][y] << ", ";
            ++y;
          }

        case 2: // for y
          std::cout << "Please, write y here: ";
          std::cin >> y;
          x = 0;
          while(x <= 4) {
            std::cout << matrix[x][y] << ", ";
            ++x;
          }
			}
    
		case 3: // all string printed
      x = 0;
      y = 0;
      while(x < 4) {
        while(y <= 4) {
          std::cout << matrix[x][y] << ", ";
          ++y;
        }
        std::cout << matrix[x][y] << ", ";
        ++x;
      }
  }
}

int main() {
	int matrix[5][5] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
  };

  std::cout << "Heyo! Here Miyo!\n";
	std::cout << "Do you want matrix?";
	char a; // answer
	std::cin >> a;
	while(a == 'y') {
    int z{matrix()};
		std::cout << "Do you wamt continue? (Y/n): ";
		std::cin >> a;
  }
  std::cout << "Bye!";
  return 0;
}
