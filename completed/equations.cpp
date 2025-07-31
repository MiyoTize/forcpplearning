#include <iostream>
#include <cmath>
using std::cout, std::cin;

void Grade1()
{ // Ax = B 
  double a, b, x;
  cout << "\nPlease, write A and B: ";
  cin >> a >> b;
  if(a == 0) {
    cout << "\nFuck! A = 0..."
         << "\nDont have x";
  } else {
    x = -b / a;
    cout << "\nHave 1 x:"
         << "\nX = " << x;
  }
};

void Grade2()
{ // Ax^2 + Bx + C = 0
  double a, b, c, D, x1, x2;
  cout << "\nWrite a, b and c: ";
  cin >> a >> b >> c;
  D = b*b - (4*a*c); 
  if(a == 0) { // Bx + C = 0
    x1 = -c / b;
  } else if(b == 0 && c <= 0) {
    x1 = sqrt(-c); // Ax^2 + C = 0
    x2 = -sqrt(-c);
  } else if(c == 0) {
    x1 = 0; // Ax^2 + Bx = 0
    x2 = -b / a;
  } else {
    if(D == 0) {
      x1 = -b / (2 * a);
    } else {
      x1 = (-b + sqrt(D)) / (2 * a);
      x2 = (-b - sqrt(D)) / (2 * a);
    }
  }
  cout << "X1 = " << x1 << "\n"
       << "X2 = " << x2 << "\n";
};

int main()
{ // Heyo from Miyo The Crazey Tize!!!
  std::cout << "\nHeyo! Here Miyo!"
/*IAmHereF*/<< "\nYou in equationsolver"
/*orOneM1s*/<< "\nPlease, write what you want solve:"
/*s1onWith*/<< "\n1. Ax + B = 0"
/*GodMeani*/<< "\n2. Ax^2 + Bx + C = 0"
/*ngAghrr~*/<< "\n(1/2): ";
  int answer;
  cin >> answer;
  if(answer == 1) {
    Grade1();
  } else if(answer == 2) {
    Grade2();
  } else {
    cout << "\nFucking fail!\n";
  }
  return 0;
}
