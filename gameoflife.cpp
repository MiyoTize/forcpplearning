#include <iostream>
#include <random>
using std::cout, std::cin, std::cerr, std::endl;
#ifdef _WIN32
  #include <windows.h>
  #define msleep(x) Sleep(x)
#else
  #include <unistd.h>
  #define msleep(x) usleep(x * 1000)
#endif

// FIEND
uint8_t i; // width
uint8_t j; // height
uint8_t height = 0;
uint8_t width = 0;

struct point {
  uint8_t live:1;
};

void init_world(point world[][height])
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 10000);

  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      uint16_t num = dis(gen);
      if (num % 2 == 0) {
        world[i][j].live = 1;
      } else {
        world[i][j].live = 0;
      }
    }
  }
};

void print(point world[][height])
{
  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      if (world[i][j].live == 1) {
        cout << 'U'; // live
      } else {
        cout << 'w'; // death
      }
      cout << ' ';
    }
    cout << "\n";
  }
};

unsigned int get_count(point world[][height])
{
  uint8_t count = 0;
  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      if (world[i][j].live == 1) {
        ++count;
      }
    }
  }
  return count;
};

void read_neighbors(int32_t nb[][2], uint8_t x, uint8_t y)
{
  uint8_t k = 0;
  for (i = --x; i <= ++x; ++i) {
    for (j = --y; j <= ++y; ++j) {
      if (i == x && j == y) {
        continue;
      }
      nb[k][0] = i;
      nb[k][1] = j;
      ++k;
    }
  }
};

unsigned int count_neighbors(point world[][height], uint8_t x, uint8_t y)
{
  uint8_t count = 0;
  int32_t nb[8][2];
  int16_t _x, _y;
  read_neighbors(nb, x, y);
  for (i = 0; i < 8; i++) {
    _x = nb[i][0];
    _y = nb[i][1];

    if (_x < 0 || _y < 0) {
      continue;
    }
    if (_x >= width || _y >= height) {
      continue;
    }
    if (world[_x][_y].live == 1) {
      ++count;
    }
  }
  return count;
};

void generation(point world[][height], point prev_world[][height])
{
  uint16_t live_nb;
  point p;
  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      p = prev_world[i][j];
      live_nb = count_neighbors(prev_world, i, j);
      if (p.live == 0) {
        if (live_nb == 3) {
          world[i][j].live = 1;
        }
      } else {
        if (live_nb < 2 || live_nb > 3) {
          world[i][j].live = 0;
        }
      }
    }
  }
};

void copy_world(point src[][height], point dest[][height])
{
  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      dest[i][j] = src[i][j];
    }
  }
};

int cmp_world(point w1[][height], point w2[][height])
{
  for (i = 0; i < width; ++i) {
    for (j = 0; j < height; ++j) {
      if (w1[i][j].live != w2[i][j].live) {
        return -1;
      }
    }
  }
  return 0;
};

int main()
{
  cout << "\nHello! My name is Miyo"
       << "\nWrite size of x-line";
  cin >> height;
  cout << "\nWrie size of y-line";
  cin >> width;
  point world[width][height];
  point prev_world[width][height];
  init_world(world);
  uint8_t live_points = -1;
  bool is_optimal = false;
  do {
    print(world);
    copy_world(world, prev_world);
    generation(world, prev_world);
    is_optimal = cmp_world(world, prev_world) == 0;
    live_points = get_count(world);

    if (is_optimal) {
      cout << "Optimal configuration detected" << endl;
    }
    if (live_points == 0) {
      cout << "All points died" << endl;
    }
    msleep(1000);
  } while (live_points != 0 && !is_optimal);
  return 0;
}
