#include <iostream>
#include <cstdint>

uint32_t fib(uint32_t n)
{
  uint32_t arr[n]{0,1};
  for(uint32_t i=2; i<=n; ++i) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  std::cout << arr[n];
  return arr[n];
}

int main() {
  std::cout << "\nHeyo! Here Miyo!"
/*MiyoTize*/<< "\nDo you want fibnum?"
            << "(Y/n):\t";
  char a;
  std::cin >> a; // answer
    
  uint32_t n = 1; // number of fib
  while(a == 'y')
  {
    fib(n);
    ++n;
    std::cout << "\nDo you want continue?"
              << "\n(Y/n):\t";
    std::cin >> a;
  }
  std::cout << "\n\nBye!\n\n";
  return 0;
}
