#include <iostream>

void fun() // 1 or 2 or 3 or 4
{
  std::cout << "Please, write what you want:\n"
/*Crazeeey*/<< "1. find sum\n"
/*Tizeeeey*/<< "2. find first penis\n"
/*Here! Yo*/<< "3. find difference\n"
/*Mayo 0_.*/<< "4. find quantity of penis\n\n"
/*Opezdoll*/<< "Write here: ";
// MiyoOoOOooOOOooOo I LOVE UUUU!!! I LOVE YOU TOO MIYOOOOO ah :O <3
}

void variants(double result) // solving
{
  double a; // firts penis
  double n; // quantity of penis
  double b; // diff of penis
  double s; // sum of penis
  int choice;
  std::cin >> choice;
	switch(choice) { // 1 or 2 or 3 or 4
    case 1:
      std::cout << "\n\nWrite a, b and n: ";
      std::cin >> a >> b >> n;
      if(n!=1 && b!=0) {
        result = a + b*(n-1); // sum
      } else {
        std::cout << "Fucking failed!\n\n";
      }
      break;

    case 2:
      std::cout << "\n\nWrite s, b and n: ";
      std::cin >> s >> b >> n;
      if(n!=1 && b!=0) {  
        result = s - b*(n-1); // first penis
      } else {
        std::cout << "Fucking failed!\n\n";
      }
      break;

    case 3:
      std::cout << "\n\nWrite s, a and n: ";
      std::cin >> s >> a >> n;
      if(n!=0 && a!=0 && s!=0) {  
        result = s / (a * n); // diff
      } else {
        std::cout << "Fucking failed!\n\n";
      }
      break;

    case 4:
      std::cout << "\n\nWrite s, a and b: ";
      std::cin >> s >> a >> b;
      int z = s - a; // the костыль for if
      if(z!=0 && b!=0) {  
        result = (s - a) / b; // quantity
      } else {
        std::cout << "Fucking failed!\n\n";
      }
      break;
    }
  std::cout << "Result: " << result;
}

int main()
{
  char answer;
  std::cout << "Heyo! Here Miyo!\n"
            << "Do you want solve something?\n\n(Y/n): ";
  std::cin >> answer; // y or n
  while (answer == 'y') {
    void fun(); // 1 or 2 or 3 or 4
    void variants(double result); // solving
    std::cout << "Do you want continue?\n\n(Y/n): ";
    std::cin >> answer;
  }
  std::cout << "\nBye!\n\n";
  return 0;
}
