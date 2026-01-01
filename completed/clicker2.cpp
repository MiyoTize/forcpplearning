#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

using std::cout, std::cin, std::endl;
using std::string;
using std::runtime_error;
using std::exception;
using std::cerr;
using std::pow;

using std::this_thread::sleep_for;
using namespace std::chrono_literals;

string miyokissing;

enum UpgradeType {
  UPGRADE_CLICK = 0,
  UPGRADE_MULT = 1,
  UPGRADE_RESET = 2,
  UPGRADE_COUNT = 3
};

struct Upgrade {
  const char* name;
  double cost;
  int level;
  
  Upgrade(const char* n, double c) : name(n), cost(c), level(0) {}
};

struct GameState
{
  double score;
  double total;
  double click_power;
  double multiplier;
  double reset_bonus;
  int reset_count;
  Upgrade upgrades[UPGRADE_COUNT];
  
  GameState() : 
    score(0), total(0), click_power(1), multiplier(1), 
    reset_bonus(2), reset_count(0),
    upgrades{
      Upgrade("Power", 10),
      Upgrade("Mult", 100),
      Upgrade("Reset", 1000)
    } {}
};

struct Terminal
{
  termios old_settings;
  termios new_settings;
  
  void setup() {
    tcgetattr(0, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_settings);
  }
  
  void restore() {
    tcsetattr(0, TCSANOW, &old_settings);
  }
  
  bool has_input() {
    timeval timeout = {0, 0};
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0, &read_fds);
    return select(1, &read_fds, NULL, NULL, &timeout) > 0;
  }
  
  char get_char() {
    char c;
    read(0, &c, 1);
    return c;
  }
};

class ClickerGame 
{
private:
  GameState state;
  Terminal terminal;
  
  void apply_upgrade_click() {
    state.click_power += 1;
    state.upgrades[UPGRADE_CLICK].cost *= 2;
  }
  
  void apply_upgrade_mult() {
    state.multiplier += 1;
    state.upgrades[UPGRADE_MULT].cost *= 2;
  }
  
  void apply_upgrade_reset() {
    ++state.reset_count;
    state.reset_bonus = pow(2, state.reset_count);
    state.upgrades[UPGRADE_RESET].cost *= 2;
  }
  
  void perform_reset() {
    state.score = 0;
    state.click_power = 1;
    state.multiplier = 1;
    
    state.upgrades[UPGRADE_CLICK].level = 0;
    state.upgrades[UPGRADE_MULT].level = 0;
    state.upgrades[UPGRADE_CLICK].cost = 10;
    state.upgrades[UPGRADE_MULT].cost = 100;
    
    ++state.reset_count;
    state.reset_bonus = pow(2, state.reset_count);
  }
  
public:
  ClickerGame() {
    terminal.setup();
  }
  
  ~ClickerGame() {
    terminal.restore();
  }
  
  void draw() {
    system("clear");
    
    cout << "=== CLICKER ==="
         << "\nScore: " << state.score << " | Total: " << state.total
         << "\nUntil reset: " << state.score << " / " 
         << state.upgrades[UPGRADE_RESET].cost
         << "\n\nClick: " << (state.click_power * state.multiplier) 
         << " | Mult: x" << state.multiplier
         << "\nResets: " << state.reset_count 
         << " | Bonus: x" << state.reset_bonus
         << "\n\n=== UPGRADES ===\n";
    
    for (int i = 0; i < UPGRADE_COUNT; ++i) {
      cout << (i + 1) << ". " << state.upgrades[i].name 
           << " Lv" << state.upgrades[i].level 
           << " (" << state.upgrades[i].cost << ")\n";
    }
    
    cout << "\n=== CONTROLS ==="
         << "\nSPACE - Click"
         << "\n1-3 - Buy upgrade"
         << "\nR - Reset (clears progress)"
         << "\nK - Special key (does nothing)"
         << "\nQ - Exit";
  }
  
  void click() {
    double damage = state.click_power * state.multiplier;
    state.score += damage;
    state.total += damage;
  }
  
  bool buy_upgrade(int upgrade_index) {
    if (upgrade_index < 0 || upgrade_index >= UPGRADE_COUNT) {
      return false;
    }
    
    Upgrade& upgrade = state.upgrades[upgrade_index];
    
    if (state.score < upgrade.cost) {
      return false;
    }
    
    state.score -= upgrade.cost;
    ++upgrade.level;
    
    switch (upgrade_index) {
      case UPGRADE_CLICK: apply_upgrade_click(); break;
      case UPGRADE_MULT: apply_upgrade_mult(); break;
      case UPGRADE_RESET: apply_upgrade_reset(); break;
    }
    
    return true;
  }
  
  bool reset_game() {
    if (state.score < state.upgrades[UPGRADE_RESET].cost) {
      return false;
    }
    
    perform_reset();
    return true;
  }
  
  void process_input(char key) {
    switch (key) {
      case ' ':
        click();
        break;
        
      case '1':
      case '2':
      case '3':
        buy_upgrade(key - '1');
        break;
        
      case 'r':
      case 'R':
        reset_game();
        break;
        
      case 'k':
      case 'K':
        cout << "\n... You... you want kiss me? Really?.."
/*Miyo >_<!*/<< "\n[answer]: ";
        cin >> miyokissing;
// написано членом по клаве и проверено
        while(miyokissing == "kiss") {
          cout << "\n*kissing~*";
          sleep_for(1000ms);
          cout << "\n~Aww~~~ *MiyoTize kissed you so hot*";
          sleep_for(1000ms);
          cout << "\n>_<... U... want kiss me again?.. *Miyo hungry waiting for you*"
               << "\n[answer]: ";
          cin >> miyokissing;
        }
        cout << "\n*Miyo now is not kind for you!*\n";
        sleep_for(2000ms);
        break;

      case 'q':
      case 'Q':
        throw runtime_error("Exit game");
    }
  }
  
  void run() {
    draw();
    
    while (true) {
      try {
        if (terminal.has_input()) {
          char key = terminal.get_char();
          process_input(key);
          draw();
        }
        sleep_for(16ms);
      } catch (const runtime_error& e) {
        break;
      }
    }
  }
};

int main() {
  try {
    ClickerGame game;
    game.run();
    return 0;
  } catch (const exception& e) {
    cerr << "Error: U are fucking stupid! Reason: " << e.what() << "\n";
    return 1;
  }
}
