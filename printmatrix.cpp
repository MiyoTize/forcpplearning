
// ITS WORK STRANGE. ILL FIX SOON

#include <iostream>

void matrix()
{
  int matrix[5][5] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
  };

  std::cout << "What do you want?\n"
            << "1. print one number of massive\n"
            << "2. print one string\n"
            << "3. print all strings\n"
            << "Please, write here: ";
  int choice;
  std::cin >> choice;
  int i{};
  int j{};
  switch(choice) {
    case 1: // print only one number
      std::cout << "Please, write a place of mAssive:\n"
                << "I: ";
      std::cin >> i;
      std::cout << "j: ";
      std::cin >> j;
      std::cout << "Result: " << matrix[i][j];
      break;    
    case 2: // print string ( i or j )
      std::cout << "Please, write i or j of massive (1 or 2): ";
      int iorj; // i or j
      std::cin >> iorj;
      if(iorj == 1) { // for i
        std::cout << "Please, write i here: ";
        std::cin >> i;
        j = 0;
        while(j < 5) {
          std::cout << matrix[i][j] << " ";
          ++j;
        }
      } else if(iorj == 2) { // for j
        std::cout << "Please, write j here: ";
        std::cin >> j;
        i = 0;
        while(i < 5) {
          std::cout << matrix[i][j] << " ";
          ++i;
        }
      } else {
        std::cout << "Try again!\n";
      }
			break;

    case 3: // print all elements
      for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
          std::cout << matrix[i][j] << " ";
        }
      }
			break;
  }
}

int main() {
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want matrix?\n(Y/n): ";
  char answer; // y or n
  std::cin >> answer;
  while(answer == 'y') {
    matrix();
    std::cout << "\n\nDo you want continue?\n(Y/n): ";
    std::cin >> answer;
  }
  std::cout << "Bye!\n";
  return 0;
}
