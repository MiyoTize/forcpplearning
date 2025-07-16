#include <iostream>
using std::cout, std::cin;

class Point {
private:
  int x;
  int y;
public: 
  int GetX() {
    return x;
  }
  void SetX(int ValueX) {
    x = ValueX;
  }

  int GetY() {
    return y; 
  }
  void SetY(int ValueY) {
    y = ValueY;
  }
  
  void Print() {
    cout << "x = " << x << ", y = " << y << "\n";
  }
};

int main() {
  int ValueX;
  int ValueY;

  Point a;
  cout << "Hi! Write here X and Y:";
  cin >> ValueX >> ValueY;
  a.SetX(ValueX);
  a.SetY(ValueY);
  a.Print();
  return 0;
}
