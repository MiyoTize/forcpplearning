#include <algorithm>

int main() {
  int fooarray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int array[]    = {5, 3, 4, 2, 0, 9, 8, 1, 6, 7}; 
  std::sort(array, array + sizeof(array) / sizeof(int));
  return 0;
}
