#include <iostream>
#include <cmath>

int parampampam(double a, double b, double &x) {
  if(a == 0) {
    return 0;
  }
  x = -b / a;
  return 1;
}

int main() {
  double a, b, x; // Ax + B = 0

  std::cout << "Heyo! Here Miyo!\n"  
            << "You in Ax + B = 0 solver\n"
            << "Please, write A and B here: ";
  std::cin >> a;
  std::cin >> b;
    
  int result = parampampam(a, b, x);
    
  if(result == 1) {
    std::cout << "\nX = " << x;
  }
  else {
    std::cout << "\nFuck! A = 0...";
  }  
  return 0;
}
