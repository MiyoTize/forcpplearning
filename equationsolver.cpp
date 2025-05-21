
// THIS CODE DOESNT WORK

#include <iostream>
#include <cmath>

int first(double a, double b, double &x) {
  if(a == 0) {
    return 0;
  }
  x = -b / a;
  return 1;
}

int second(double a, double b, double c) {
  double a, b, c, D, x1, x2;
  D = b * b - (4 * a * c);

  if(a == 0) {
    x1 = -c / b;
    return 0; // Bx + C = 0
  }
  else if(b == 0 && c <= 0) {
    x1 = sqrt(-c);
    x2 = -sqrt(-c);
    return 1; // Ax^2 + C = 0
  }
  else if(c == 0) {
    x1 = 0;
    x2 = -a
    return 2; // Ax^2 + B = 0
  }
  return return;
}

int main() {
  double a, b, x; // Ax + B = 0
  int answer; 
  std::cout << "Heyo! Here Miyo!\n"  
            << "You in equationsolver\n"
            << "Please, write what you want solve:\n"
            << "1. Ax + B = 0\n"
            << "2. Ax^2 + Bx + C = 0\n"
            << "(1/2):";
  std::cim >> answer;
  if(answer == 1) {
    int w = operfirst();
  }
  else if(answer == 2) {
    int q = opersecond();
  }
  else {
    std::cout << "\nFuckimg fail!\n";
  }


int operfirst() {
  std::cout << "Please, write A and B: ";
  std::cin >> a;
  std::cin >> b;
    
  int result = first(a, b, x);
    
  if(result == 1) {
    std::cout << "\nX = " << x;
  }
  else {
    std::cout << "\nFuck! A = 0...";
  }  
  return 0;
}

int opersecond() {
  std::cout << "Please, write A, B and C: ";
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

  int result = second(a, b, c);

  if(result == 1) {
    std::cout << "x1 = " << x1 << "\n"
              << "x2 = " << x2;
  
