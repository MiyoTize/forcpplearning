#include <iostream>
#include <string>
using std::cout, std::cin, std::string;

class Dog {
private:
  string name;
  string voice;
public:
  Dog(string p_name, string p_voice) {
    name = p_name;
    voice = p_voice;
  }
  void print() {
    cout << "Name: " << name << "\nDog said: " << voice << "\n";
  }
  string getName() {
    return name;
  }
  string getVoice() {
    return voice;
  }
};

int main() {  
  // How many dogs you have?
  Dog person{"NotMiyo", "woof!~"};
  person.print();
  return 0;
}
