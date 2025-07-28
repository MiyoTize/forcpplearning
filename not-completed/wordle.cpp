#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>

using std::cout, std::cin, std::string;

class Words {
private:
  string word;  // real word
  uint8_t size; // size of word
public:
  Word(string p_word, uint8_t p_size) {
  }
  word = p_word;
  string getword() {
    return word;
  }
  size = p_size
  uint8_t getsize() {
    getword();
    size = word.size();
    return size;
  }
};

int main()
{
  Words words;
  words.word = "labubu";
  words.getword();
  words.getsize();
  return 0;
}
