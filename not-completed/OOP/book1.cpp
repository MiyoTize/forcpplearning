#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

class Book {
private:
  string title;
  string author;
  int year;
  bool isAvailable;

public: 
  Book(string t, string a, int y) {
    title = t;
    author = a;
    if (y > 0 && y < 2026) {
      year = y;
    } else {
      year = 2025;
      cout << "Warning: Invalid year set to default" << endl;
    }
    isAvailable = true;
  }

  void takeBook() {
    if (isAvailable) {
      isAvailable = false;
      cout << "You took the book: " << title << endl;
    } else {
      cout << "Book is already taken" << endl; 
    }
  }
  void returnBook() {
    isAvailable = true;
    cout << "Book returned" << endl;
  }
  void printInfo() {
    cout << "'" << title << "' by " << author << " (" << year << ")" << endl;
    cout << (isAvailable ? "Avaiable" : "Not Avaiable") << endl;
  }
};

int main() {
  cout << "\nYo!!! Miyo Crazeyest here!\n";
  // BOOKS
  Book myBook("1984", "George Orwell", 1949);
  // FUNCTIONS
  myBook.printInfo();
  myBook.takeBook();
  myBook.takeBook();
  myBook.returnBook();
  myBook.printInfo();
  Book invalidbook("Some Book", "Author", -100);
  return 0;
}
