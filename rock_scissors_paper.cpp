#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::string;

uint8_t win;
uint8_t lose;

int choice()
{ // 1, 2 or 3. else: >:(
  cout << "\nPlease, write your choice"
/*Miy*/<< "\n[1]: Rock"
/*oTi*/<< "\n[2]: Scissors"
/*zen*/<< "\n[3]: Paper"
       << "\nHere: ";
  uint8_t obj; // rock(1), scissors(2) or paper(3)
  cin >> obj;
  uint8_t size = 3;
  string objarray[size] = {"Rock", "Scissors", "Paper"};
  while(obj>size && obj<1)
  {
    cout << "\nFail! Try again!\n\n";
    cin >> obj;
  }
  cout << "\nYour choice is " << objarray[obj] << ", right?"
       << "\nY/n: ";
  char answer;
  cin >> answer;
  while(answer == 'n')
  { // shit this code used 2 times noo ;( 
    cin >> obj;
    while(obj!=1 && obj!=2 && obj!=3)
    {
      cout << "\nFail! Try again!\n\n";
      cin >> obj;
    }
  }
  return 0;
};

int play()
{
  std::srand(std::time(0)); // machine choice
  int random = (std::rand() % 4);
  uint8_t obj;
  if((obj==1 && random==3) || (obj==2 && random==1) || (obj==3 && random==2))
{ // win
  std::cout << "You win!";
  ++win; // :10 global
} else { // lose
  std::cout << "You lose!";
  ++lose; // :11 global
  return 0;
};

int main() 
{
  cout << "\nHeyo! I am MiyoTize the Crazey Tizey Dikiyan Aanas"
       << "\nDo you want start this game?\nY/n: ";
  char answer;
  cin >> answer;
  while(answer == 'y')
  { 
    choice();
    play();
    cout << "\nWins: " << win
         << "\nLoses: " << lose;
    cout << "\n\nDo you want play again?\nY/n: ";
    cin >> answer;
  }
  return 0;
}
