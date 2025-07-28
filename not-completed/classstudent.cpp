#include <iostream>
#include <string>
#include <cstdint>
/*Crazyeeee Tizeeeey*/
using std::cout, std::cin, std::endl, std::string;

class Student
{
private:
  string name;
  uint16_t age = {}; // stupid kid
	string mail;
  string password;
  uint8_t grade;

  enum gender { // only 2 !!!
    male,
    female
  };

public:
  string GetСredentials() {
    return mail;
    return password;
  }
  void SetCredentials() {
    cin >> mail;
    cin >> password;
  };
	void input() {
    cout << "\nWrite your name, age, gender and grade\nHere: ";
    cin >> name >> age >> gender;
  };

  while(gender!="male" && gender!="female") {
    cout << "\n\n\nGET OUT!!!\nGET OUT!!!\nGET OUT!!!\n\n\n";
    cout << "Write gender here, asshole!: ";
    cin >> gender;
  }
  cout << "\nWrite here email (without @mail.comG): ";
  SetCredentials();
  
  void print() {
    cout << "\nName: "   << name
/*MiyoThe*/<< "\nAge: "    << age
/*Crazyee*/<< "\nGender: " << gender << endl;
  }
};

int main()
{
  Student person;
  cout << "\nHeyo! MiyoTize Kislyy here!"
/*Hi!*/<< "\nYou a student/teacher?\n";
  string answer; // student or teacher
  cin >> answer;
/*Too much lines. Get chill, reader! This code doesnt work!!! Vlad is angry! Br-rr! RuWust is my fav >_<*/
  if(answer == "teacher") {
    person.print();
	} else if(answer == "student") {
    person.input();
  } else {
    cout << "\nTry again!\n";
    return 0;
  }
  cout << "\n\nBye!\n\n";
  return 0;
} // Добавить функцию "ОТЧИСЛЕН!!!"
