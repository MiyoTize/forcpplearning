#include <iostream>
#include <string>
#include <vector>
using std::cout, std::cin, std::string, std::vector;

class Dog {
private:
  string name;
  string voice;
public:
  Dog(string new_name, string new_voice);
  Dog(string new_name);
};
Dog::Dog(string new_name, string new_voice) {
  name = new_name;
  voice = new_voice;
}
Dog::Dog(string new_name) : Dog(new_name, voice) {}
void Dog::print() {
  cout << "\nName: " << name << "\nWhat dog said: " << voice << "\n"; 
}

int main() {
  vector<Dog> dogs;
  char answer; // y or n
  string new_name;
  string new_voice;
  cout << "\nHello! my name is Miyo, and this is my game";
  cout << "\nDo you want start? Y/n: ";
  cin >> answer;
  while(answer == 'y') {
    cout << "\nGood, write name of your dog: ";
    cin >> new_name;
    cout << "\nWrite whats dog talk about?";
    cin >> new_voice;
    dogs.push_back(Dog(new_name, ));
  }
  for(const auto& dog : dogs) {
    Dog::print();
  }
  return 0;
}
