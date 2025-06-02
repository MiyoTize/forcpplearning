#include <iostream>
#include <string>

class Student
{
  public:
    std::string name;
    unsigned age;
    std::string gender;
    void print() {
      std::cout << "\nName: "   << name
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
  if(answer == 'y') {
    std::cout << "Write your name, age and gender\nhere: ";
    std::cin >> student.name >> student.age >> student.gender;
    ptr->print();
  }
  std::cout << "\n\nBye!\n\n";
  return 0;
}
