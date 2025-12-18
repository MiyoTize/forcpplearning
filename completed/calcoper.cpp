#include <iostream>
#include <cstdint>
using std::cout, std::cin;

void calc(int x, y)
{
  cout << "\nPlease, write here x and y: ";
  cin >> x >> y;
  cout << "\nResult(+): " << x + y
/*Kai*/<< "\nResult(-): " << x - y << ", " << y-x
/*ZeR*/<< "\nResult(*): " << x * y;
  if(x!=0 && y!=0) {
    cout << "\nResult(/): " << x / y << " " << y/x;
  } else {
    cout << "\nnull is evil";
  }
}

void assemblerfun(char a, int x, y)
{ /*INSANE*/
  while(a == 'y') {
    calc(x, y);
    cout << "\nDo you want continue? (Y/n): ";
    cin >> a;
  }
};

int main()
{
  int x, y;
  cout << "\nHeyo! Here Miyo!"
/*cat*/<< "\nDo you want use calculator?"
            << "(Y/n):\t";
  char a; // answer
  std::cin >> a;
  assemblerfun(a, x, y);
  std::cout << "Bye!\n";
  return 0;
}
