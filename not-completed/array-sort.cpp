#include <iostream>
#include <algorithm>
#include <vector>

void firstsort()
{
  int array[] = {-2, 5, -1, 1, 0, -3, 4, 2, 3, -5, -4};
  int size = sizeof(array) / sizeof(array[0]);
  std::vector<int> positive_array;
  std::vector<int> negative_array;
  for (int i = 0; i < size; ++i) {
    if (array[i] >= 0) {
      positive_array.push_back(array[i]);
    } else {
      negative_array.push_back(array[i]);
    }
  } // MiyoTize
  std::cout << "\nPositive numbers: ";
  for (int num : positive_array) {
    std::cout << num << ' ';
  }
  std::cout << "\nNegative numbers: ";
  for (int num : negative_array) {
    std::cout << num << ' ';
  }
};

void secondsort()
{
  int array[] = {5, 3, 4, 2, 0, 9, 8, 1, 6, 7};
  int size = sizeof(array) / sizeof(array[0]);
  std::sort(array, array + size); // sorter
  std::cout << "\nSorted array: ";
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
};

int main() 
{ // Miyo The Crazey Tize
  std::cout << "\nHeyo, MiyoTize here!"
/*MiyoTize*/<< "\nFirst array: ";
  firstsort();
  std::cout << "\nSecond array: ";
  secondsort();
  std::cout << "\nBye!!!\n";
  return 0;
}
