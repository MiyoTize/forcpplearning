#include <iostream>

int calc() {
  int x;
  int y;
  std::cout << "\nPlease, write here x and y:";
  std::cin >> x >> y;

  std::cout << "\nResult(+): " << x+y
            << "\nResult(-): " << x-y << " " << y-x
            << "\nResult(*): " << x*y;
  if(x!=0 && y!=0) {
    std::cout << "\nResult(/): " << x/y << " " << y/x;
  }
  else {
    std::cout << "0 is evil";
  }
  return 0;
}

int main() {
  int x, y;
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want use calculator? (Y/n): ";
  char a; // answer
  std::cin >> a;
  while(a == 'y') {
    int z = calc();
    std::cout << "Do you want continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
  return 0;
}
