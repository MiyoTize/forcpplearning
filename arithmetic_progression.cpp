#include <iostream>

int main() {
  int a, n, b, s; // firts penis, quantity of penis, diff and sum
  char answer;
  std::cout << "Heyo! Here Miyo!\n";
  std::cout << "Do you want solve? (Y/n): ";
  std::cin >> answer;
  while(answer == 'y') {
    std::cout << "Please, write what you want:\n1. find sum\n2. find first penis\n3. find difference\n4. find quantity of penis\n: ";
    int choice;
    double result;
    std::cin >> choice;
	  
    switch(choice) {
      case 1:
        std::cout << "\nWrite a, b and n: ";
        std::cin >> a, b, n;
	if(n!=1 && b!=0) {
          result = a + b*(n-1); // sum
	}
        else {
          std::cout << "Fucking failed!";
          return 0;
	}
      case 2:
        std::cout << "\nWrite s, b and n: ";
        std::cin >> s, b, n;
        result = s - b*(n-1); // first penis

      case 3:
        std::cout << "\nWrite s, a and n: ";
        std::cin >> s, a, n;
        result = s / (a * n); // diff

      case 4:
        std::cout << "\nWrite s, a and b: ";
        std::cin >> s, a, b;
        result = (s - a) / b; // quantity
    };
    std::cout << "Result: ";
    return result;
  }
  std::cout << "Bye!";
  return 0;
};

