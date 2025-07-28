#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <ctime>
using std::cout, std::cin, std::string;

enum gameOption {
  paper,
  rock,
  scissors,
};

enum gameResult {
  win,
  defeat,
  draw,
};

const gameResult gameResultMatrix[3][3] = {
    {draw, win, defeat},
    {defeat, draw, win},
    {win, defeat, draw},
};

gameOption randomOption();
gameOption inputOption();
gameResult evalGame(gameOption p1, gameOption p2);
string formatGame(gameOption g);
string formatGameResult(gameResult g);
void printMenu();

int main() {
  srand(time(nullptr));
  printMenu();
  gameOption yourOption = inputOption();
  gameOption enemyOption = randomOption();
  cout << "your object is: " << formatGame(yourOption) << '\n';
  cout << "enemy object is: " << formatGame(enemyOption) << '\n';
  cout << "result: " << formatGameResult(evalGame(yourOption, enemyOption)) << '\n';
  return 0;
}

void printMenu() {
  cout << "Select One:\n"
/*Miy*/<< "\t1 - Paper\n"
/*oTi*/<< "\t2 - Rock\n"
/*zen*/<< "\t3 - Scissors\n";
}

gameOption randomOption() { return static_cast<gameOption>(rand() % 3); }

gameOption inputOption() {
  size_t gameIdx;
  cin >> gameIdx;
  return static_cast<gameOption>(gameIdx - 1);
}

gameResult evalGame(gameOption p1, gameOption p2) {
  return gameResultMatrix[p1][p2];
}

string formatGame(gameOption g) {
  if (g == 0) {
    return "paper";
  } else if (g == 1) {
    return "rock";
  } else {
    return "scissors";
  }
}

string formatGameResult(gameResult g) {
  if (g == win) {
    return "win";
  } else if (g == defeat) {
    return "defeat";
  } else {
    return "draw";
  }
}
