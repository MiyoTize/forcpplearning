#include <iostream>

int click(int x) { // for clicks
  int y;
  std::cout << x << " + 1 = ";
  std::cin >> y;
  while (y == x + 1) {
    ++x; // result looks like x + 1 = ++x
    std::cout << "\nTrue!\n"
              << x << " + 1 = ";
    std::cin >> y;
  }
  return x;
}

int main() {
  int x;
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want play in clicker?\n"
            << "You need click 1000 times. (1/0):\n";
  char a; // answer
  std::cin >> a;
  if (a == 'y') {
    while (x <= 1000) {
      int z{click(x)};
    }
  } else {
    std::cout << "Bye!";
    return 0;
  }
}
