#include <iostream>

int fib(int n) {
  int arr[n]{0,1};
  for(int i=2; i<=n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  std::cout << arr[n];
  return arr[n];
}

int main() {
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want fibnum? (Y/n): ";
  char a;
  std::cin >> a; // asnwer
    
  int n = 1; // number of fib
  while(a == 'y') {
    fib(n);
    ++n;
    std::cout << "\nDo you want continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
  return 0;
}
