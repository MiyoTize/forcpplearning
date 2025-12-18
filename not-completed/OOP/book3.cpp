#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

classLibraryItem {
protected:
  string title;
  int year;
  bool is Available;

public:
  LIbraryItem(string t, int y)
    : title(t), year(y), isAvailable(true) {
    cout << "New LibraryItem: " << title << endl;
  }  

  virtual void takeItem() {
    if (isAvailable) {
      isAvailable = false;
      cout << title << " in using" << endl;

int main() {

  return 0;
}
