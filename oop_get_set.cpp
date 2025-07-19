#include <iostream>
using std::cout, std::cin;

class Point {
private:
  int x, y;
public: 
  int GetX() {
    return x;
  }
  void SetX() {
    cin >> x;
  }

  int GetY() {
    return y; 
  }
  void SetY() {
    cin >> y;
  }
  
  void Print() {
    cout << "x = " << x << ", y = " << y << "\n";
  }
};

int main() {
  Point out;
  cout << "\nHi! Write here X and Y:";
  out.SetX();
  out.SetY();
  out.Print();
  return 0;
}
