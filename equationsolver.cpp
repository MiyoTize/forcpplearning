
// THIS CODE DOESNT WORK?

#include <iostream>
#include <cmath>

int first(double a, double b, double &x) {
  int result;
  if(a == 0) {
    result = 0;
  } 
  else {
    x = -b / a;
    result = 1;
  }
  return result;
}
int operfirst() {
  int result;
  std::cout << "Please, write A and B: ";
  std::cin >> a;
  std::cin >> b;
  int result;
  int endfirst = first(a, b, x);   
  if(result == 1) {
    std::cout << "\nX = " << x;
  }
  else {
    std::cout << "\nFuck! A = 0...";
  }  
  return 0;
}

// NEW BLOCK
// NEW BLOCK
// NEW BLOCK

int second(double a, double b, double c) {
  int result;
  double a, b, c, D, x1, x2;
  D = b * b - (4 * a * c); 
  if(a == 0) { 
    x1 = -c / b;
    result = 0; // Bx + C = 0
  }
  else if(b == 0 && c <= 0) {
    x1 = sqrt(-c);
    x2 = -sqrt(-c);
    result = 1; // Ax^2 + C = 0
  } 
  else if(c == 0) {
    x1 = 0;
    x2 = -b / a;
    result = 2; // Ax^2 + Bx = 0\
  } 
  else {
    if(D < 0) {
      result = 3; // Dont have x1 or x2
    }   
    else if (D == 0) {
      x1 = -b / (2 * a);
      result = 4;
    }
    else {
      x1 = (-b + sqrt(D)) / (2 * a);
      x2 = (-b - sqrt(D)) / (2 * a);
      result = 5;
    }
  }
  return result;
}
int opersecond() {
  std::cout << "Please, write A, B and C: ";
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  int result;
  int endsecond = second(a, b, c);
  if(result == 1 or 2 or 5) {
    std::cout << "x1 = " << x1 << "\n"
              << "x2 = " << x2;
    return 0;
  }
  else if(result == 0 or 4) {
    std::cout << "x1 = " << x1 << "\n"
    return 0;
  }
  else {
    std::cout << "Fucking fail!\n";
    return 0;
  }
  
int main() {
  double a, b, c, D, x, x1, x2; // Ax + B = 0
  int answer; 
  std::cout << "Heyo! Here Miyo!\n"  
            << "You in equationsolver\n"
            << "Please, write what you want solve:\n"
            << "1. Ax + B = 0\n"
            << "2. Ax^2 + Bx + C = 0\n"
            << "(1/2):";
  std::cin >> answer;
  if(answer == 1) {
    int w = operfirst();
  }
  else if(answer == 2) {
    int q = opersecond();
  }
  else {
    std::cout << "\nFuckimg fail!\n";
  }
