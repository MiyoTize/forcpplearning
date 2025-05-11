#include <iostream>
#include <string>

int main() {
  std::cout << "Heyo! Maybe you want solve something? Y/n" << std::endl;
  std::cin << std::string answer{};

  switch(answer) { // request a response from the user to continue the program
    case 1:
      if (answer = 'y') { // yes
        std::cout << "Super!" << '\n';
      };
    case 2:
      if (answer = 'n') { // no
        std::cout << "Sadness. << '\n';
          break;
      };
   };

std::cout << "Write first number please: " << double x << '\n';
std::cout << "Write second number please: " << double y << '\n';

std::cout << "What you want? +, -, *, / ?" << '\n' >> std::cin << int symbol;
  switch(symbol) {
    case '+':
      std::cout << "Result: " << x + y << std::endl;
      return 0;
    case '-':
      std::cout << "Result: " << x - y << std::endl;
      rerurn 0;
    case '*':
      std::cout << "Result: " << x * y << std::endl;
      rerurn 0;
    case '/':
      std::cout << "Result: " << x / y << std::endl;
      rerurn 0;
  };
    std::cout << "Please, try again" << '\n';
    return 0;
  };
      
      
   



