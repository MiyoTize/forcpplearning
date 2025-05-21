#include <iostream>
#include <vector>

int main() {
  int mooarr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  int arr[]    = {-2, 5, -1, 1, 0, -3, 4, 2, 3, -5, -4};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::vector<int> positive_arr;
  std::vector<int> negative_arr;

  for (int i = 0; i < n; ++i) {
    if (arr[i] >= 0) {
      positive_arr.push_back(arr[i]);
    }
    else {
      negative_arr.push_back(arr[i]);
    }
  }

  std::cout << "Heyo! Here Miyo!\n"
            << "Positive numbers: ";
  for (int num : positive_arr) {
    std::cout << num << "\n";
  }

  std::cout << "Negative numbers: ";
  for (int num : negative_arr) {
    std::cout << num << " ";
  }
  return 0;
}
