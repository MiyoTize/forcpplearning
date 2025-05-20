
// THIS CRAZY CODE DOESNT WORK. FIX SOON

#include <iostream>

int click() { // for clicks
  std::cout << x << " + 1 = ";
  std::cin >> y;
  if(y == ' ') {
    ++x; // result looks like x + 1 = ++x
    std::cout << x << "\n";
  }
  return 0;
}

int main() {
  int x = 0;
  char y;
  std::cout << "Heyo! Here Miyo Kislyy!"
            << "Do you want play in clicker? You need click 1000 times. (Y/n): ";
  char a; // answer
  std::cin >> a;
  if(a == 'y') {
    while(x <= 1000) {
      int z{click()};
    }
  }
  std::cout << "Bye!";
  return 0;
}
