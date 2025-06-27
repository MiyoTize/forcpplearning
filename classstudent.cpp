#include <iostream>
#include <string>
#include <cstdint>
/*Crazyeeee Tizeeeey*/
using std::string;

class Student
{
private:
  string name;
  uint16_t age; // stupid kid
  string gender;

	string mail;
  string password;

public:
  string pmail;     // public mail
  string ppassword; // public password

	void input() { 
  std::cout << "\nWrite your name, age and gender\nHere: ";
  std::cin >> name >> age >> gender;

  if(gender!="male" && gender!="female") {
    std::cout << "\n\n\nGET OUT!!!\nGET OUT!!!\nGET OUT!!!\n\n\n";
    
  }
  std::cout << "\nWrite here email (without @mail.com) "
/*MiyoTize*/<< "and password\nHere: ";
  std::cin >> pmail >> ppassword;

  mail = pmail;
	password = ppassword;
  pmail.clear();
  ppassword.clear();
	}

  void print() {
    std::cout << "\nName: "   << name << pmail << ppassword
              << "\nAge: "    << age
              << "\nGender: " << gender << std::endl;
  }
};

int main()
{
  Student student;
  Student *ptr = &student;
  std::cout << "\nHeyo! MiyoTize Kislyy here!"
            << "\nDo i right? You a student?\n(Y/n): ";
  char answer;
  std::cin >> answer;
  while(answer == 'y') {
    ptr->input();
    ptr->print();
    std::cout << "Do you want continue?\n(Y/n):\t";
    std::cin >> answer;
	}
  std::cout << "\n\nBye!\n\n";
  return 0;
}
