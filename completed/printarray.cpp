#include <iostream>
#include <string>
using std::cout, std::cin, std::string;

void array()
{ // alg for make/print matrix
  uint32_t i{}, j{}, h, w, dim; // dimension
  // DIMENSION CHOICE
  cout << "\nChoose dimension of array: ";
  cin >> dim;
  // ARRAY CREATION
  cout << "\nChoose matrix size:"
       << "\nheight: ";
  cin >> h;
  cout << "width: ";
  cin >> w;
  uint32_t array[h][w]{};
  // ARRAY FILLING
  uint32_t counter = 0;
  for(i = 0; i < h; ++i) {
    for(j = 0; j < w; ++j) {
      array[i][j] = ++counter;
    } 
  }
  // PRINTING
  cout << "\nWhat do you want print?"
       << "\n[1] - print one index"
       << "\n[2] - print one index string"
       << "\n[3] - print all index strings"
       << "\nWrite here: ";
  uint16_t print; // 1, 2 or 3
  cin >> print;
  switch(print) 
  { // VARIANTS
    case 1: // print one number
      cout << "\nWrite index"
           << "\ni: ";
      cin >> i;
      cout << "\nj: ";
      cin >> j;
      cout << "\nResult: " << array[i][j];
      break;    

    case 2: // print string ( i or j )
      cout << "\nChoose index:"
           << "\n[1] - i"
           << "\n[2] - j"
           << "\nWrite number here: ";
      uint16_t iorj; // i or j
      cin >> iorj;
      if(iorj == 1) { // for i
        cout << "\nWrite i: ";
        cin >> i;
        j = 0;
        cout << "\nResult:\n";
        while(j < w) {
          cout << array[i][j] << ' ';
          ++j;
        }
      } else if(iorj == 2) { // for j
        cout << "\nWrite j: ";
        cin >> j;
        i = 0;
        cout << "\nResult:\n";
        while(i < h) {
          std::cout << array[i][j] << ' ';
          ++i;
        }
      } else {
        cout << "\nTry again!\n";
      }
      break;

    case 3: // print all elements
      cout << "\nResult:\n";
      for (i = 0; i < h; ++i) {
        cout << "\n";
        for (j = 0; j < w; ++j) {
          cout << array[i][j] << ' ';
        }
      }
      break;
  }
};

int main() 
{
  cout << "\nHeyo! Here Miyo!"
       << "\nDo you want matrix? Y/n: ";
  char answer; // y or n
  cin >> answer;
  while(answer == 'y') {
    array();
    cout << "\n\nDo you want continue? Y/n: ";
    cin >> answer;
  }
  while (answer == 'u') {
    cout << "\nMe?.. A... >_<. OK, u can kiss me.\n";
    string kiss;
    cin >> kiss;
    if(kiss == "kiss") {
      cout << "\nAah~.. (Miyo kissed you)"
           << "\nI love you.\n";
    }
  }
  cout << "\nBye!\n";
  return 0;
}
