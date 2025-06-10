#include <iostream>
#include <cstdint>
#include <bitset>

class Bitset
{
  public:
    Bitset(std::uint32_t b_number)
    {
      number = b_number;
      std::bitset<16> number;
      std::cout << "\n" << number;
    }

    ~Bitset()
    {
      std::cout << "\nDeleted!";
    }

  private:
  std::uint32_t number;

};

void fun(std::uint32_t b_number, char answer)
{ 
  while(answer == 'y')
  {
		std::cout << "\nWrite number here: ";
    std::cin >> b_number;
    Bitset out{b_number};

    std::cout << "\nDo you want continue?"
              << "(Y/n):\t";
    std::cin >> answer;
  }
};


int main() {
	std::uint32_t b_number;
  char answer;
  std::cout << "\nHeyo! Its a Miyo!"
            << "\n\nDo you want start?"
            << "\n(Y/n):\t";
  std::cin >> answer;
  fun(b_number, answer);
  std::cout << "\n\nBye!!!\n\n";
  return 0;
}
