#include <iostream>
#include <string>

int main() {
  std::cout << "Heyo! Maybe you want solve something? Y/n" << std::endl;
  std::string answer;
  std::cin >> answer;

  switch(answer) { // request a response from the user to continue the program
    case 1:
      if (answer == 'y') { // yes
        std::cout << "Super!" << '\n';
      };
    case 2:
      if (answer == 'n') { // no
        std::cout << "Sadness." << '\n';
          break;
      std::cout << "Try again!" << std::endl;
      return 0;
      };
   };
	
  double x, y;
  std::cout << "Write first number please: " << '\n';
  std::cin >> x;
  std::cout << "Write second number please: " << '\n';
  std::cin >> y;

  std::cout << "What you want? +, -, *, / ?" << '\n'
  std::string symbol;
  std::cin >> symbol;
  switch(symbol) {
    case '+':
      std::cout <<"Result: " << x + y << std::endl;
    case '-':
      std::cout << "Result: " << x - y << std::endl;
    case '*':
      std::cout << "Result: " << x * y << std::endl;
    case '/':
      std::cout << "Result: " << x / y << std::endl;
    return 0;
  };
  std::cout << "Please, try again" << '\n';
  return 0;
};
