#include <iostream>

int main() {
  char operation, cont;
  int a, b;
  // the result can be 5 / 2 = 2.5 so it should not be an integer
  double result;

  for (;;) {
    std::cout << "Enter expression, example: 2 + 2:\n";
    std::cin >> a >> operation >> b;

    switch (operation) {
    case '+':
      result = a + b;
      break;

    case '-':
      result = a - b;
      break;

    case '*':
      result = a * b;
      break;

    case '/':
      // implicit cast to double because a is an integer
      // 10   / 3 = 3
      // 10.0 / 3 = 3.33333
      result = (double)a / b;
      break;
    }

    std::cout << "the expression " << a << ' ' << operation << ' ' << b
              << " equals: " << result << '\n';

    std::cout << "Wanna continue?(y/n)\n";
    std::cin >> cont;
    if (cont == 'n')
      break;
  }
  std::cout << "bye!\n";
  return 0;
}