#include <iostream>
#include <algorithm>
using std::cout;

int main() {
  int i = 10;
  int fooarray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int array[i]   = {5, 3, 4, 2, 0, 9, 8, 1, 6, 7};
  std::sort(array, array + sizeof(array) / sizeof(int));
  for (i = 0; i <= sizeof(array); ++i) {
    cout << i << ' ';
  }
  return 0;
}
