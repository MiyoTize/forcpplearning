#include <iostream>
#include <cmath>

int calc()
{
  double x, y;
  std::cout << "\nWrite x and y please: ";
  std::cin >> x >> y;

  std::cout << "What you want?\n"
/*:)*/<< "1. +\t"
/*im*/<< "2. -\n"
/*Mi*/<< "3. *\t"
/*yo*/<< "4. /\n"
/*Ti*/<< "5. pow\t"
/*ze*/<< "6. sqrt\n"
/*Ha*/<< "7. log\t"
/*Ha*/<< "8. round\n\n"
/*Ha*/<< "Write here: ";
  unsigned number;
  std::cin >> number; // symbol or word
  std::cout << "\n\nResult:\n\n";
  switch(number) {
    case 1:
      std::cout << "x + y = " << x + y << "\n\n";
      return 0;

    case 2:
      std::cout << "x - y = " << x - y << "\n"
                << "y - x = " << y - x << "\n\n";
      return 0;
	  
    case 3:
      std::cout << "x * y = " << x * y << "\n\n";
      return 0;
	  
    case 4:
      if(x!=0 && y!=0) {
        std::cout << "x / y = " << x / y << "\n" 
                  << "y / x = " << y / x << "\n\n"; 
      }
      else {
        std::cout << "Fucking fail!" << "\n\n";
      }
      return 0;
	  
    case 5:
      std::cout << "pow(x, y) = " << pow(x, y) << "\n"
                << "pow(y, x) = " << pow(y, x) << "\n\n";
      return 0;
	  
    case 6:
      if(x>=0 && y>=0) {
        std::cout << "sqrt(x) = " << sqrt(x) << "\n"
                  << "sqrt(y) = " << sqrt(y) << "\n\n";
      } else {
        std::cout << "Fucking fail!" << "\n\n";
      }
      return 0;
	  
    case 7:
      if(x>=0 && y>=0) {
        std::cout << "log(x) = " << log(x) << "\n"
                  << "log(y) = " << log(y) << "\n\n";
      } else {
        std::cout << "Fucking fail!" << "\n\n";
      }
      return 0;
	  
    case 8:
      std::cout << "round(x) = " << round(x) << "\n"
                << "round(y) = " << round(y) << "\n\n";
  }
  return 0;
}

int main()
{
  std::cout << "Heyo! Here Miyo Kislyy :)" << "\n"
            << "Maybe you want solve something?\n\n(Y/n): ";
  char answer;
  std::cin >> answer; // answer

  while(answer == 'y') {
    calc();
    std::cout << "Do you want continue? (Y/n): ";
    std::cin >> answer;
  }
  std::cout << "\n\nBye!\n\n";
  return 0;
}
