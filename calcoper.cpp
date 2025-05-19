#include <iostream>

int calc() {
  int x;
  int y;
  std::cout << "\nPlease, write here x and y:";
  std::cin >> x, y;

  std::cout << "\nResult(+): " << x+y;
  std::cout << "\nResult(-): " << x-y << " " << y-x;
  std::cout << "\nResult(*): " << x*y;
  if(x!=0 && y!=0) {
    std::cout << "\nResult(/): " << x/y << " " << y/x;
  }
  else {
    std::cout << "0 is evil";
  }
  return 0;
}

int main() {
  std::cout << "Heyo! Here Miyo!\n";
  std::cout << "Do you want use calculator? (Y/n):";
  char a; // answer
  std::cin >> a;
  while(a == 'y') {
    int z = calc();
    std::cout << "\nDo you want continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
  return 0;
}
