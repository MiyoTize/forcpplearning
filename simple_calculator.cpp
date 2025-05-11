#include <iostream>

int main() {
  std::cout << "Heyo! Maybe you want solve something? Y/n" << std::endl;
  char a;
    std::cin >> a; // answer

  switch(a) { // request a response from the user to continue the program
    case 'y':
      std::cout << "Super!" << '\n';
      break;

    case 'n':
      std::cout << "Sadness." << '\n';
      break;

  std::cout << "Try again!" << std::endl;
  return 0;
  };
	
  double x, y;
  std::cout << "Write first number please: ";
  std::cin >> x;
  std::cout << "Write second number please: ";
  std::cin >> y;

  std::cout << "What you want? +, -, *, / ? ";
  char s;
  std::cin >> s; // symbol
  switch(s) {
    case '+':
      std::cout <<"Result: " << x + y << std::endl;
      break;
		
    case '-':
      std::cout << "Result: " << x - y << std::endl;
      break;
		
    case '*':
      std::cout << "Result: " << x * y << std::endl;
      break;
		
    case '/':
      std::cout << "Result: " << x / y << std::endl;
      break;
  };

  std::cout << "Please, try again" << '\n';
  return 0;
};
