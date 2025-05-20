
// THIS CODE DOESNT WORK

#include <iostream>

int sum(double, double, double, double, double) {
  std::cout << "Please, write the number: ";
  double num;
  std::cin >> num;
  std::cout << "\n";
  return num;
}

int main() {
  std::cout << "Heyo! Here Miyo!\n"
            << "Please, write numbers for sentences: ";
  double x = sum();
  double y = sum();
  double z = sum();
  double a = sum();
  double b = sum();

  std::cout << "Right? Numbers: " << x << " " << y << " " << z << " " << a << " " << b << " (Y/n): ";
  char answer;
  if(answer == 'y') {
    std::cout << "Result: " << x + y + z + a + b;
  }
  else {
    std::cout << "Ooooops... Try again, please";
  }
  return 0;
}

// what the fuck is it? do i write this shit omg...
