#include <iostream>
#include <cstdint>
using std::cout, std::cin;

uint64_t fib(uint64_t n)
{
  uint64_t arr[n]{0,1};
  for(uint64_t i=2; i<=n; ++i) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  cout << arr[n];
  return arr[n];
}

int main() {
  cout << "\nHeyo! Here Miyo!"
/*Hey*/<< "\nDo you want fibnum?"
       << "\n(Y/n): ";
  char a;
  cin >> a; // answer
    
  uint64_t n = 1; // number of fib
  while(a == 'y')
  {
    fib(n);
    ++n;
    cout << "\nDo you want continue?"
         << "\n(Y/n):\t";
    cin >> a;
  }
  cout << "\n\nBye!\n\n";
  return 0;
}
