#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

void creator() {
  cout << "\nFuck you!\n";
};

void kiss() {
  cout << "\nYou want kiss me?.. okay.. (hot kiss~)"
       << "\nI love you...~"
       << "\nKiss again?";
};

int main() {
  std::string password;
  std::string answer;
  cout << "\nHeyo? Miyo The Crazey here!"
       << "\nDo you want create password? (Y/n): ";
  cin >> answer;
  if (answer == "y" || "yes" || "Y" || "Yes") { 
    creator();
  } else if (answer == "kiss") {
    kiss();
  } else {
    cout << "eh";
  }
  return 0;
}
