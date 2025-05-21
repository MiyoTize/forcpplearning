
// ITS WORK STRANGE. ILL FIX SOON

#include <iostream>

int matrix() {
  int m[5][5] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
  };

  std::cout << "What do you want?\n"
	    << "(1) - print one number of massive\n"
	    << "(2) - print one string\n"
	    << "(3) - print all strings\n"
            << "Please, write here: ";
	
  int choice;
  std::cin >> choice;
  int i{};
  int j{};
  switch(choice) {
    case 1: // printed only one number
      std::cout << "Please, write a place of mAssive: ";
      std::cin >> i, j;
      std::cout << "Result: " << m[i][j];
      return 0;
    
    case 2: // printed string ( i or j )
      std::cout << "Please, write i or j of massive (1 or 2): ";
      char iorj; // i or j
      std::cin >> iorj;
      switch(iorj) {
        case 1: // for i
          std::cout << "Please, write i here: ";
          std::cin >> i;
          j = 0;
          while(j <= 5) {
            std::cout << m[i][j] << ", ";
            ++j;
          }

        case 2: // for j
          std::cout << "Please, write j here: ";
          std::cin >> j;
          i = 0;
          while(i <= 5) {
            std::cout << m[i][j] << ", ";
            ++i;
          }
	}
    
    case 3: // all string printed
      i = 0;
      j = 0;
      while(i < 5) {
        while(j <= 5) {
          std::cout << m[i][j] << ", ";
          ++j;
        }
        std::cout << m[i][j] << ", ";
        ++i;
      }
  }
  return 0;
}

int main() {
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want matrix?";
  char a; // answer
  std::cin >> a;
  while(a == 'y') {
    int z{matrix()};
    std::cout << "\nDo you wamt continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
  return 0;
}
