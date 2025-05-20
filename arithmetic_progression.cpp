
// THIS CODE WORKS BADLY, ILL FIX IT SOON

#include <iostream>

int main() {
  char answer;
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want solve? (Y/n): ";
  std::cin >> answer;
	
  while(answer == 'y') {
    std::cout << "Please, write what you want:\n1. find sum\n2. find first penis\n3. find difference\n4. find quantity of penis\n: ";
    double result;
    int choice; // 1 or 2 or 3 or 4
    std::cin >> choice;
    int a, n, b, s; // firts penis, quantity of penis, diff and sum

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
      	if(n!=1 && b!=0) {  
          result = s - b*(n-1); // first penis
        }
        else {
          std::cout << "Fucking failed!";
          return 0;
        }

      case 3:
        std::cout << "\nWrite s, a and n: ";
        std::cin >> s, a, n;
      	if(n!=0 && a!=0 && s!=0) {  
          result = s / (a * n); // diff
        }
        else {
          std::cout << "Fucking failed!";
          return 0;
        }

      case 4:
        std::cout << "\nWrite s, a and b: ";
        std::cin >> s, a, b;
        int z = s - a; // the костыль for if
      	if(z!=0 && b!=0) {  
          result = (s - a) / b; // quantity
        }
        else {
          std::cout << "Fucking failed!";
          return 0;
        }

    };
    std::cout << "Result: ";
    return result;
  }
  std::cout << "Bye!";
  return 0;
}
