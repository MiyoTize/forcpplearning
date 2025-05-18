
// THIS CODE DOESNT WORK

#include <iostream>

int main() {
  std::cout << "Heyo! Here Miyo!\n";
  std::cout << "Do you want solve something? (Y/n): ";
  char answer; // y or n from user
  std::cin >> answer;
  
  std::cout << "\nHow many times You want use my code?\n";
  std::cout << "Please, write here: ";
  int n, m, z = 0; // n - how many times, z - strange way, but
  std::cin >> n;

  while(z!=n && n>0) {
    if(answer == 'y') {
      int x;
      int y;
      std::cout << "\nPlease, write here x and y:";
      std::cin >> x, y;

      std::cout << "\nResult(+): " << m{x+y};
      std::cout << "\nResult(-): " << m{x-y};
      std::cout << "\nResult(*): " << m{x*y};
      std::cout << "\nResult(/): " << m{x/y} << "\n";
    }
    else {
      break;
    }
    ++z;
  }
  std::cout << "Bye!" << std::endl;
  return 0;
}
