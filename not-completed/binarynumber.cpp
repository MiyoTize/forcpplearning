#include <iostream>
#include <bitset>
#include <string>
using std::cout, std::cin, std::string;

class Bitset
{
private:
  string word;

public:
  Bitset(string value) : word(value) {
    cout << "\nYour word is: " << word;
    std::bitset<4> word;
    cout << "\nYour number with bitset is: " << word;
  }

  ~Bitset() {
    cout << "\nDeleted!";
  }
};

int main()
{
  char answer;
  string n;
  cout << "\nHeyo! Its a Miyo!"
       << "\nDo you want start?"
       << "\n(Y/n): ";
  cin >> answer;
  while(answer == 'y') {
    cout << "\nWrite word here: ";
    cin >> n;
    Bitset obj(n);
    cout << "\nDo you want continue?"
         << "\n(Y/n): ";
    cin >> answer;
  }
  cout << "\n\nBye!!!\n\n";
  return 0;
}
