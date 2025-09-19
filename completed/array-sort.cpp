#include <iostream>
#include <stdlib.h>
using std::cout;

int sortcomp(const void * a, const void * b)
{
  return( *(int*)a - *(int*)b );
};

void sort()
{
  int array[] = {-2, 5, -1, 1, 0, -3, 4, 2, 3, -5, -4};
  int size = sizeof(array) / sizeof(array[0]);
  qsort (array, size, sizeof(int), sortcomp);
  for (int i = 0; i < size; ++i) {
	  cout << array[i]<<" ";
  }
};

int main() 
{ // Miyo The Crazey Tize
  cout << "Heyo, MiyoTize here!"
/*Hi!*/<< "\nSorted array: ";
  sort();
  cout << "\nBye!!!\n";
  return 0;
}
