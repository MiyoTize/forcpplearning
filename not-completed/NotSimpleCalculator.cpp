
// ITS DOESNT WORK U SEE?????????

#include <iostream>
#include <cmath>

int ftext(char answer) { // first text
  char answer;
  std::cout << "Heyo! Here Miyo!\n"
            << "You in NotSimpleCalculator. Missclick or you want start?\n"
            << "(Y/n): ";
  std::cin >> answer; // answer
}

int stext(int choice) { // second text
  int choice; // number of:
  std::cout << "You have a choice:\n"
            << "1. Arrays\n"
            << "2. Matrix ( 1d or 2d )\n"
            << "3. Based meth\n"
            << "4. Bitwise operations\n"
  std::cin >> choice;
}



int out() {
  if ...
    1
  else if ...
    2
}

int main() {
  char answer;
  int z = text();
  while(a == 'y') {
    int q = out();
    std::cout << "Do you want start again? (Y/n): ";
    std::cin >> answer;
  }
  std::cout << "\nBye!";
  return 0;
}
