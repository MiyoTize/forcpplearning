#include <iostream>
#include <random>
using std::cout, std::cin;

void gen() {
  cout << "\nWrite k1, k2, h and w: ";
  uint32_t k1, k2, h, w; // coef., height and width
  cin >> k1 >> k2 >> h >> w;
  uint32_t matrix[h][w];
  for(uint32_t i = 0; i < h; ++i) {
    cout << "\n";
    for(uint32_t j = 0; j < w; ++j) {
      matrix[i][j] = rand() % (k2-k1+1);
      cout << matrix[i][j] << ' ';
    }
  }
};

int main() {
  gen();
  return 0;
}
