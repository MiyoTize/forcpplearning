#include <iostream>
#include <cmath>

int calc() {
  double x, y;
  std::cout << "Write x and y please: ";
  std::cin >> x >> y;

  std::cout << "What you want?\n"
	    << "1.+\n"
	    << "2.-\n"
	    << "3.*\n"
	    << "4./\n"
	    << "5.p (pow)\n"
	    << "6.s (sqrt)\n"
	    << "7.l (log)\n"
	    << "8.r (round)\n"
	    << "Write here: ";
  char s;
  std::cin >> s; // symbol or word
  std::cout << "\nResult:\n";
  switch(s) {
    case '+':
      std::cout << "x + y = " << x + y << "\n";
      return 0;
	  
    case '-':
      std::cout << "x - y = " << x - y << "\n"
                << "y - x = " << y - x << "\n";
      return 0;
	  
    case '*':
      std::cout << "x * y = " << x + y << "\n";
      return 0;
	  
    case '/':
      if(x!=0 && y!=0) {
        std::cout << "x / y = " << x / y << "\n" 
                  << "y / x = " << y / x << "\n"; 
      }
      else {
        std::cout << "Fucking fail!" << "\n";
      }
      return 0;
	  
    case 'p':
      std::cout << "pow(x, y) = " << pow(x, y) << "\n"
                << "pow(y, x) = " << pow(y, x) << "\n";
      return 0;
	  
    case 's':
      if(x>=0 && y>=0) {
        std::cout << "sqrt(x) = " << sqrt(x) << "\n"
                  << "sqrt(y) = " << sqrt(y) << "\n";
      } else {
        std::cout << "Fucking fail!" << "\n";
      }
      return 0;
	  
    case 'l':
      if(x>=0 && y>=0) {
        std::cout << "log(x) = " << log(x) << "\n"
                  << "log(y) = " << log(y) << "\n";
      } else {
        std::cout << "Fucking fail!" << "\n";
      }
      return 0;
	  
    case 'r':
      std::cout << "round(x) = " << round(x) << "\n"
                << "round(y) = " << round(y) << "\n";
      return 0;
  }
  return 0;
}

int main() {
  std::cout << "Heyo! Here Miyo Kislyy :)" << "\n"
            << "Maybe you want solve something? Y/n ";
  char a;
  std::cin >> a; // answer
  while(a == 'y') {
    int z = calc();
    std::cout << "Do you want continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
}
