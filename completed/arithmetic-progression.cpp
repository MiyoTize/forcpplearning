#include <iostream>
using std::cout, std::cin, std::endl;

void ways() 
{ // 1 or 2 or 3 or 4
  cout << "Please, write what you want:\n"
/*Cry*/<< "1. find sum\n"
       << "2. find first penis\n"
       << "3. find difference\n"
       << "4. find quantity of penis\n\n"
       << "Write here: ";
// MiyoOoOOooOOOooOo I LOVE UUUU!!! I LOVE YOU TOO MIYOOOOO ah :O <3
}

void solving() 
{ // solving
  double a; // firts penis
  double n; // quantity of penis
  double b; // diff of penis
  double s; // sum of penis
  double result;
  uint8_t choice;
  cin >> choice;
  while(choice <= 0 && choice > 4) {
    cout << "Write your choice again: ";
    cin >> choice;
  }
  if(choice == 1) {
    cout << "\n\nWrite a, b and n: ";
    cin >> a >> b >> n;
    if(n!=1 && b!=0) {
      result = a + b*(n-1); // sum
    } else {
      cout << "Fucking failed!\n\n";
    }
  } else if(choice == 2) {
    cout << "\n\nWrite s, b and n: ";
    cin >> s >> b >> n;
    if(n!=1 && b!=0) {  
      result = s - b*(n-1); // first penis
    } else {
      cout << "Fucking failed!\n\n";
    }
  } else if (choice == 3) {
    cout << "\n\nWrite s, a and n: ";
    cin >> s >> a >> n;
    if(n!=0 && a!=0 && s!=0) {  
      result = s / (a * n); // diff
    } else {
/*Yo*/cout << "Fucking failed!\n\n";
    }
  } else {
    cout << "\n\nWrite s, a and b: ";
    cin >> s >> a >> b;
    double z = s - a; // the костыль for if
    if(z!=0 && b!=0) {  
      result = (s - a) / b; // quantity
    } else {
      cout << "Fucking failed!\n\n";
    }
  }
  cout << "Result: " << result;
};

int main()
{
  char answer;
  cout << "\nHeyo! Here Miyo!"
       << "\nDo you want solve something?\n(Y/n): ";
  cin >> answer; // y or n
  while (answer == 'y') {
    ways();
    solving();
    cout << "\nDo you want continue?\n\n(Y/n): ";
    cin >> answer;
  }
  cout << "\n\nBye!\n\n";
  return 0;
}
