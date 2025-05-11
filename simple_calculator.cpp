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

   



