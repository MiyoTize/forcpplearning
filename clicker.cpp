#include <iostream>

int click() { // for clicks
  int x = 0;
	int y;
  std::cout << x << " + 1 = ";
  std::cin >> y;
  while (++x == y) {
    // result looks like x + 1 = ++x
    std::cout << "True!\n"
              << x << " + 1 = ";
    std::cin >> y;
  }
  std::cout << "\nFucking fail!\n\n";
  return 0;
}

int main() {
  int x;
  std::cout << "Heyo! Here Miyo!\n"
            << "Lets start!\n\n";
  click();
  std::cout << "Bye!\n\n";
  return 0;
}

