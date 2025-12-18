#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

class LibraryItem {
protected:
  string title;
  int year;
  bool isAvailable;

public:
  LibraryItem(string t, int y) : title(t), year(y), isAvailable(true) {}
  virtual void takeItem() {
    if (isAvailable) {
      isAvailable = false;
      cout << title << "taken" << endl;
    } else {
      cout << title << " is not available" << endl;
    }
  }

  void returnItem() {
    isAvailable = true;
    cout << title << " returned" << endl;
  }
  virtual void printInfo() {
    cout << "'" << title << "' (" << year << "). ";
    cout << (isAvailable ? "Available" : "Not available") << endl;
  }
  virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
  string author;
  int pages;

public:
  Book(string t, string a, int y, int p) : LibraryItem(t, y), author(a), pages(p) {}
  
  void printInfo() override {
    cout << "BOOK: ";
    LibraryItem::printInfo();
    cout << "Author: " << author << ", Pages: " << pages << endl;
  }
  void readFragment() {
    cout << "Reading a fragment from " << title << "..." << endl;
  }
};  

class Magazine : public LibraryItem {
private:
  int issueNumber;

public:
  Magazine(string t, int y, int issue) : LibraryItem(t, y), issueNumber(issue) {}
  void printInfo() override {
    cout << "Magazine: ";
    LibraryItem::printInfo();
    cout << "Issue: #" << issueNumber << endl;
  }
  void takeItem() override {
    if (isAvailable) {
      isAvailable = false;
      cout << title << " (magazine) #" << issueNumber << ") taken for 7 days only" << endl;
    } else {
      cout << "Magazine is already taken" << endl;
    }
  }
};

int main() {
  cout << "\nHeyo? MiyoTize here.\n";
  Book book("The C++ Programming Language", "Bjarne Stroustrup", 2013, 1376);
  Magazine magazine("National Geographic", 2025, 5);
// MiyoTize
  cout << "\n=== Initial info ===" << endl;
  book.printInfo();
  magazine.printInfo();
// Carzey
  cout << "\n=== Taking items ===" << endl;
  book.takeItem();
  magazine.takeItem();
// Kislyy Master~
  cout << "\n=== Trying to take again ===" << endl;
  book.takeItem();
// Knowledge-hunter
  cout << "\n=== Specific method ===" << endl;
  book.readFragment();
  return 0;
}
