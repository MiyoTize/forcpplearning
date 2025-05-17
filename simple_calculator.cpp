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
  switch(s) {
    case '+':
      std::cout << "Result:\nx + y = " << x + y << std::endl;
      return 0;
		
    case '-':
      std::cout << "Result:\nx - y = " << x - y << ", y -x = " << y - x << std::endl;
      return 0;
		
    case '*':
      std::cout << "Result:\nx + y = " << x + y << std::endl;
      return 0;
		
    case '/':
      std::cout << "Result:\nx / y = " << x / y << ", y / x = " << y / x << std::endl;
      return 0;
	  
    case 'p':
      std::cout << "Result:\npow(x, y)  = " << pow(x, y) << ", pow(y, x) = " << pow(y, x) << std::endl;
      return 0;
	  
    case 's':
      std::cout << "Result:\nsqrt(x) = " << sqrt(x) << ", sqrt(y) = " << sqrt(y) << std::endl;
      return 0;

    case 'l':
      std::cout << "Result:\nlog(x) = " << log(x) << ", log(y) = " << log(y) << std::endl;
      return 0;

    case 'r':
      std::cout << "Result:\n round(x) = " << round(x) << ", round(y) = " << round(y) << std::endl;
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
  return 0;
}
