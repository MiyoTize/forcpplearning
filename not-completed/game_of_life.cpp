#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <sys/select.h>
#include <unistd.h>
#include <termios.h>

using namespace std;
using namespace std::chrono_literals;

// ========== КОНФИГ ==========
struct Config {
  int w = 20, h = 40;
  int fps = 15;
  float density = 0.25f;
  bool wrap = true;
  char alive = '#', dead = ' ';
  bool color = true;
  int auto_reset = 0;
  string title = "GAME OF LIFE by MiyoTize";
};

// ========== ASCII АРТ ==========
namespace Art {
  const vector<string> BANNER = {
    "▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████    █████▒    ██▓     ██▓  █████▒▓█████ ",
    " ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██   ▒    ▓██▒    ▓██▒▓██   ▒ ▓█   ▀ ",
    "▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒▒████ ░    ▒██░    ▒██▒▒████ ░ ▒███   ",
    "░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░░▓█▒  ░    ▒██░    ░██░░▓█▒  ░ ▒▓█  ▄ ",
    "░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░░▒█░       ░██████▒░██░░▒█░    ░▒████▒",
    " ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░  ▒ ░       ░ ▒░▓  ░░▓   ▒ ░    ░░ ▒░ ░",
    "  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░  ░         ░ ░ ▒  ░ ▒ ░ ░       ░ ░  ░",
    "░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒   ░ ░         ░ ░    ▒ ░ ░ ░       ░   ",
    " ▄▄▄▄ ▓██   ██▓  ░ ███▄ ▄███▓ ██▓▓██   ██▓ ▒█████  ▄▄▄█████▓ ██▓▒███████▒▓█████   ░  ░",
    "▓█████▄▒██  ██▒   ▓██▒▀█▀ ██▒▓██▒ ▒██  ██▒▒██▒  ██▒▓  ██▒ ▓▒▓██▒▒ ▒ ▒ ▄▀░▓█   ▀       ",
    "▒██▒ ▄██▒██ ██░   ▓██    ▓██░▒██▒  ▒██ ██░▒██░  ██▒▒ ▓██░ ▒░▒██▒░ ▒ ▄▀▒░ ▒███         ",
    "▒██░█▀  ░ ▐██▓░   ▒██    ▒██ ░██░  ░ ▐██▓░▒██   ██░░ ▓██▓ ░ ░██░  ▄▀▒   ░▒▓█  ▄       ",
    "░▓█  ▀█▓░ ██▒▓░   ▒██▒   ░██▒░██░  ░ ██▒▓░░ ████▓▒░  ▒██▒ ░ ░██░▒███████▒░▒████▒      ",
    "░▒▓███▀▒ ██▒▒▒    ░ ▒░   ░  ░░▓     ██▒▒▒ ░ ▒░▒░▒░   ▒ ░░   ░▓  ░▒▒ ▓░▒░▒░░ ▒░ ░      ",
    "▒░▒   ░▓██ ░▒░    ░  ░      ░ ▒ ░ ▓██ ░▒░   ░ ▒ ▒░     ░     ▒ ░░░▒ ▒ ░ ▒ ░ ░  ░      ",
    " ░    ░▒ ▒ ░░     ░      ░    ▒ ░ ▒ ▒ ░░  ░ ░ ░ ▒    ░       ▒ ░░ ░ ░ ░ ░   ░         ",
    " ░     ░ ░               ░    ░   ░ ░         ░ ░            ░    ░ ░       ░  ░      ",
    "      ░░ ░                        ░ ░                           ░                     "
  };
  
  const vector<string> LOGO = {
    "========================================",
    "|   CELLULAR AUTOMATA SIMULATOR v2.0  |",
    "========================================"
  };
//MiyoTize The CRAZEYEST is listening :?
  void printCentered(const string& text, int width = 80) {
    int pad = (width - text.length()) / 2;
    if (pad < 0) pad = 0;
    cout << string(pad, ' ') << text << endl;
  }
  
  void printBox(const vector<string>& lines) {
    size_t max_len = 0;
    for (const auto& line : lines) {
      max_len = max(max_len, line.length());
    }
    
    cout << "+" << string(max_len + 2, '-') << "+\n";
    for (const auto& line : lines) {
      cout << "| " << line << string(max_len - line.length(), ' ') << " |\n";
    }
    cout << "+" << string(max_len + 2, '-') << "+\n";
  }
}

// ========== УМНЫЙ ВВОД ==========
namespace Input {
  template<typename T>
  T ask(const string& q, T def, T min, T max, const string& unit = "") {
    while (true) {
      cout << " > " << q << " [" << min << "-" << max << "]";
      if (def != T{-1}) {
        cout << " (Enter = " << def;
        if (!unit.empty()) cout << unit;
        cout << ")";
      }
      cout << "\n > ";
//shittypartbutheworks
      string s;
      getline(cin, s);
      
      if (s.empty() && def != T{-1}) return def;
      
      try {
        if constexpr (is_same_v<T, int>) {
          int v = stoi(s);
          if (v >= min && v <= max) return v;
        } else if constexpr (is_same_v<T, float>) {
          float v = stof(s);
          if (v >= min && v <= max) return v;
          v = stof(s) / 100;
          if (v >= min && v <= max) return v;
        }
      } catch (...) {}
      
      cout << " > Invalid input. Try again.\n";
    }
  }
  
  bool yesno(const string& q, bool def) {
    cout << " > " << q << " [" << (def ? "Y/n" : "y/N") << "]\n > ";
    
    string s;
    getline(cin, s);
    
    if (s.empty()) return def;
    char c = tolower(s[0]);
    return c == 'y' || c == '1';
  }
  
  char symbol(const string& q, char def) {
    cout << " > " << q << " (Enter = '" << def << "')\n > ";
    
    string s;
    getline(cin, s);
    
    return s.empty() ? def : s[0];
  }
}

// ========== ЯДРО АВТОМАТА ==========
class CellularAutomaton {
  Config cfg;
  vector<vector<bool>> curr, next;
  int gen = 0;
  int stagnation = 0;
  int last_change = 0;
  
  inline int neighbors(int y, int x) const {
    int cnt = 0;
    
    if (cfg.wrap) {
      int y_up = (y - 1 + cfg.h) % cfg.h;
      int y_down = (y + 1) % cfg.h;
      int x_left = (x - 1 + cfg.w) % cfg.w;
      int x_right = (x + 1) % cfg.w;
      
      cnt += curr[y_up][x_left];
      cnt += curr[y_up][x];
      cnt += curr[y_up][x_right];
      cnt += curr[y][x_left];
      cnt += curr[y][x_right];
      cnt += curr[y_down][x_left];
      cnt += curr[y_down][x];
      cnt += curr[y_down][x_right];
    } else {
      for (int dy = -1; dy <= 1; dy++) {
        int ny = y + dy;
        if (ny < 0 || ny >= cfg.h) continue;
        
        for (int dx = -1; dx <= 1; dx++) {
          if (dy == 0 && dx == 0) continue;
          
          int nx = x + dx;
          if (nx < 0 || nx >= cfg.w) continue;
          
          if (curr[ny][nx]) cnt++;
        }
      }
    }
    
    return cnt;
  }
  
  bool isStagnant() {
    if (gen < 10) return false;
    
    int alive = 0;
    for (const auto& row : curr) {
      for (bool cell : row) {
        if (cell) alive++;
      }
    }
    
    int change_threshold = cfg.w * cfg.h * 0.01f;
    if (abs(alive - last_change) < change_threshold) {
      stagnation++;
      return stagnation > 50;
    } else {
      last_change = alive;
      stagnation = 0;
      return false;
    }
  }
  
public:
  CellularAutomaton(const Config& c) : cfg(c) { reset(); }
  
  void reset() {
    curr.assign(cfg.h, vector<bool>(cfg.w, false));
    next.assign(cfg.h, vector<bool>(cfg.w, false));
    
    srand(time(nullptr));
    
    for (int y = 0; y < cfg.h; y++) {
      for (int x = 0; x < cfg.w; x++) {
        curr[y][x] = (float)rand() / RAND_MAX < cfg.density;
      }
    }
    
    addGlider(cfg.w / 3, cfg.h / 3);
    if (cfg.w > 10 && cfg.h > 10) {
      addBlinker(cfg.w / 2, cfg.h / 2);
    }
    
    gen = stagnation = last_change = 0;
  }
  
  void addGlider(int x, int y) {
    if (x + 2 < cfg.w && y + 2 < cfg.h) {
      curr[y][x+1] = true;
      curr[y+1][x+2] = true;
      curr[y+2][x] = true;
      curr[y+2][x+1] = true;
      curr[y+2][x+2] = true;
    }
  }
  
  void addBlinker(int x, int y) {
    if (x + 2 < cfg.w) {
      curr[y][x] = true;
      curr[y][x+1] = true;
      curr[y][x+2] = true;
    }
  }
  
  void step() {
    if (cfg.auto_reset > 0) {
      if (gen % cfg.auto_reset == 0 && gen > 0) {
        cout << "\n[ Auto-reset every " << cfg.auto_reset << " generations ]\n";
        this_thread::sleep_for(500ms); 
        reset();
        return;
      }
      
      if (isStagnant()) {
        cout << "\n[ Stagnation detected. Auto-reset... ]\n";
        this_thread::sleep_for(500ms);
        reset();
        return;
      }
    }
    
    #pragma omp parallel for if (cfg.w * cfg.h > 5000)
    for (int y = 0; y < cfg.h; y++) {
      for (int x = 0; x < cfg.w; x++) {
        int n = neighbors(y, x);
        next[y][x] = curr[y][x] ? (n == 2 || n == 3) : (n == 3);
      }
    }
    
    swap(curr, next);
    gen++;
  }
  
  void render() const {
    cout << "\033[2J\033[1;1H";
    
    cout << "\n";
    Art::printCentered(cfg.title, cfg.w + 4);
    cout << "\n";
    
    cout << "+" << string(cfg.w, '-') << "+\n";
    
    for (int y = 0; y < cfg.h; y++) {
      cout << "|";
      for (int x = 0; x < cfg.w; x++) {
        if (curr[y][x]) {
          if (cfg.color) {
            int n = neighbors(y, x);
            if (n < 2) cout << "\033[97m";
            else if (n < 4) cout << "\033[92m";
            else cout << "\033[91m";
          }
          cout << cfg.alive;
          if (cfg.color) cout << "\033[0m";
        } else {
          cout << cfg.dead;
        }
      }
      cout << "|\n";
    }
    
    cout << "+" << string(cfg.w, '-') << "+\n";
    
    cout << "\n Generation: " << gen;
    cout << " | Size: " << cfg.w << "x" << cfg.h;
    cout << " | FPS: " << cfg.fps;
    cout << "\n Borders: " << (cfg.wrap ? "wrap" : "walls");
    cout << " | Auto-reset: ";
    if (cfg.auto_reset > 0) cout << "every " << cfg.auto_reset << " gens";
    else cout << "off";
    
    cout << "\n\n [SPACE] Pause | [R] Reset | [Q] Quit | [C] Randomize\n";
  }
  
  void randomize() {
    for (int y = 0; y < cfg.h; y++) {
      for (int x = 0; x < cfg.w; x++) {
        curr[y][x] = rand() % 100 < 30;
      }
    }
    gen = 0;
  }
  
  int generation() const { return gen; }
  const Config& config() const { return cfg; }
};

// ========== НАСТРОЙКА ==========
Config setup() {
  Config c;
  
  cout << "\n";
  for (const auto& line : Art::BANNER) {
    Art::printCentered(line);
  }
  cout << "\n";
  
  Art::printBox({
    "Welcome to Cellular Automata Simulator!",
    "Configure parameters for simulation."
  });
  
  cout << "\n=== FIELD SIZE ===\n";
  c.w = Input::ask("World width", 30, 2, 2147483647);
  c.h = Input::ask("World height", 15, 2, 2147483647);
  
  cout << "\n=== SIMULATION PARAMETERS ===\n";
  c.fps = Input::ask("Speed (FPS)", 30, 1, 960);
  c.density = Input::ask("Initial density", 0.25f, 0.05f, 0.95f);
  
  cout << "\n=== AUTO-RESET ===\n";
  cout << " 0 = off, N = reset every N generations\n";
  c.auto_reset = Input::ask("Auto-reset period", 0, 0, 1000000);
  
  cout << "\n=== BORDERS ===\n";
  cout << " Wrap: world wraps around\n";
  cout << " Walls: world edges are barriers\n";
  c.wrap = Input::yesno("Use wrap-around borders?", true);
  
  cout << "\n=== APPEARANCE ===\n";
  c.color = Input::yesno("Color output?", true);
  c.alive = Input::symbol("Live cell symbol", '#');
  c.dead = Input::symbol("Dead cell symbol", ' ');
  
  cout << "\n=== TITLE ===\n";
  cout << " > Enter simulation title (Enter = 'GAME OF LIFE')\n > ";
  getline(cin, c.title);
  if (c.title.empty()) c.title = "GAME OF LIFE";
  
  cout << "\n[ Settings saved! ]\n";
  cout << " Size: " << c.w << "x" << c.h;
  cout << " | FPS: " << c.fps;
  cout << " | Auto-reset: " << (c.auto_reset ? "every " + to_string(c.auto_reset) + " gens" : "off");
  cout << "\n Starting in 2 seconds...\n";
  
  this_thread::sleep_for(2s);
  return c;
}

// ========== УПРАВЛЕНИЕ ТЕРМИНАЛОМ ==========
void setTerminalMode(bool raw) {
  static struct termios oldt, newt;

  if (raw) {
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  } else {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  }
}

bool kbhit() {
  struct timeval tv = {0, 0};
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

// ========== ГЛАВНЫЙ ЦИКЛ ==========
int main() {
  try {
    Config cfg = setup();
    CellularAutomaton game(cfg);
    
    const int frame_time = 1000 / cfg.fps;
    bool paused = false;
    
    while (true) {
      auto start = chrono::steady_clock::now();
      
      game.render();
      
      setTerminalMode(true);
      if (kbhit()) {
        char ch = getchar();
        switch (ch) {
          case ' ': paused = !paused; break;
          case 'r': case 'R': game.reset(); break;
          case 'c': case 'C': game.randomize(); break;
          case 'q': case 'Q': 
            setTerminalMode(false);
            cout << "\n[ Goodbye! ]\n";
            return 0;
          case 'k': case 'K':
            setTerminalMode(false);
            string miyokissing;
            cout << "\n... You... you want kiss me? Really?.."
/*kissMiyo >_<!*/<< "\n[answer]: ";
            cin >> miyokissing;
// написано членом по клаве и проверено
            while(miyokissing == "kiss") {
              cout << "\n*kissing~*";
              this_thread::sleep_for(1000ms);
              cout << "\n~Aww~~~ *MiyoTize kissed you so hot*";
              this_thread::sleep_for(1000ms);
              cout << "\n>_<... U... want kiss me again?.. *Miyo hungry waiting for you*"
/*Much kind Miyo~*/<< "\n[answer]: ";
              cin >> miyokissing;
            }
            cout << "\n*Miyo now is not kind for you!*";
            this_thread::sleep_for(2000ms);
            setTerminalMode(true);
        }
      }
      setTerminalMode(false);
      if (!paused) game.step();

      auto end = chrono::steady_clock::now();
      auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
      
      if (elapsed.count() < frame_time) {
        this_thread::sleep_for(chrono::milliseconds(frame_time - elapsed.count()));
      }
    }
  } catch (const exception& e) {
    setTerminalMode(false);
    cerr << "\n[ Error: " << e.what() << ". Is mean: you are FUCKING stupid! ]\n";
    return 1;
  }
  
  return 0;
}
