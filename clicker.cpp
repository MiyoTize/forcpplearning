#include <iostream>

void click() { // for clicks
  int x = 0, y;
  std::cout << x << " + 1 = ";
  std::cin >> y;
  while (++x == y) {
    // result looks like x + 1 = ++x
    std::cout << "True!\n"
              << x << " + 1 = ";
    std::cin >> y;
  }
  std::cout << "\nFucking fail!\n\n";
}

int main() {
  std::cout << "Heyo! Here Miyo!\n"
            << "Lets start!\n\n";
  click();
  std::cout << "Bye!\n\n";
  return 0;
}

// HOW ITS WORKS:
// Heyo! Here Miyo!
// Lets start!
//
// 0 + 1 = ( write 1 or DEATHHH )
// True!
// 1 + 1 = ...
// Crazey Tizeeey
// if user are stupid:
// 0 + 1 = 2
//
// Fucking fail!
//
// Bye!
