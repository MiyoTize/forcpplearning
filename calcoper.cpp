#include <iostream>
#include <cstdint>

void calc(uint32_t x, uint32_t y)
{
  std::cout << "\nPlease, write here x and y:\n";
  std::cin >> x >> y;
  std::cout << "\nResult(+): " << x + y
/*MiyoTize*/<< "\nResult(-): " << x - y << " " << y-x
/*kislyyyy*/<< "\nResult(*): " << x * y;
  if(x!=0 && y!=0) {
    std::cout << "\nResult(/): " << x / y << " " << y/x;
  } else {
    std::cout << "0 is evil";
  }
}

void assemblerfun(char a, uint32_t x, uint32_t y)
{
  while(a == 'y') {
    calc(x, y);
    std::cout << "\nDo you want continue? (Y/n): ";
    std::cin >> a;
  }
}

int main()
{
  uint32_t x, y;
  std::cout << "\nHeyo! Here Miyo!"
/*sauerkat*/<< "\nDo you want use calculator?"
            << "(Y/n):\t";
  char a; // answer
  std::cin >> a;
  assemblerfun(a, x, y);
  std::cout << "Bye!\n";
  return 0;
}
