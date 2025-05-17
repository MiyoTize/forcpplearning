#include <iostream>
#include <cmath>

int calc() {
  double x, y;
  std::cout << "Write first number please: ";
  std::cin >> x;
  std::cout << "Write second number please: ";
  std::cin >> y;

  std::cout << "What you want?\n1.+\n2.-\n3.*\n4./\n5.p (pow)\n6.s (sqrt)\n7.l (log)\n8.r (round)\nWrite here: ";
  char s;
  std::cin >> s; // symbol or word
  std::cout << "Result:\n";
  switch(s) {
    case '+':
      std::cout << "x + y = " << x + y << std::endl;
      return 0;
	  
    case '-':
      std::cout << "x - y = " << x - y << std::endl;
      std::cout << "y - x = " << y - x << std::endl;
      return 0;
	  
    case '*':
      std::cout << "x * y = " << x + y << std::endl;
      return 0;
	  
    case '/':
      if(x!=0 && y!=0) {
        std::cout << "x / y = " << x / y << std::endl; 
        std::cout << "y / x = " << y / x << std::endl; 
      }
      else {
        std::cout << "Fucking fail!" << std::endl;
      }
      return 0;
	  
    case 'p':
      std::cout << "pow(x, y) = " << pow(x, y) << std::endl;
      std::cout << "pow(y, x) = " << pow(y, x) << std::endl;
      return 0;
	  
    case 's':
      if(x>=0 && y>=0) {
        std::cout << "sqrt(x) = " << sqrt(x) << std::endl;
        std::cout << "sqrt(y) = " << sqrt(y) << std::endl;
      }
      else {
        std::cout << "Fucking fail!" << std::endl;
      }
      return 0;
	  
    case 'l':
      if(x>=0 && y>=0) {
        std::cout << "log(x) = " << log(x) << std::endl;
        std::cout << "log(y) = " << log(y) << std::endl;
      }
      else {
        std::cout << "Fucking fail!" << std::endl;
      }
      return 0;
	  
    case 'r':
      std::cout << "round(x) = " << round(x) << std::endl;
      std::cout << "round(y) = " << round(y) << std::endl;
      return 0;
  }
  return 0;
}

int main() {
  std::cout << "Heyo! Here Miyo Kislyy :)" << '\n';
  std::cout << "Maybe you want solve something? Y/n ";
  char a;
  std::cin >> a; // answer
  while(a == 'y') {
    int z{calc()};
    std::cout << "Do you want continue? (Y/n): ";
    std::cin >> a;
  }
  std::cout << "Bye!";
}
