#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using std::setw, std::fixed, std::string, std::vector, std::cout, std::cin, std::endl;

class Transaction {
private:
  string category;
  double amount;
  string date;
  string type;

public:
  Transaction(const string& cat, double amt, const string& dt)
  : category(cat), amount(amt), date(dt) {
  type = (amount >= 0) ? "income" : "expense";
  }

  string getCategory() const { return category; }
  double getAmount() const { return amount; }
  string getDate() const { return date; }
  string getType() const { return type; }

  void print() const {
    cout << setw(12) << date << " | "
         << setw(15) << category << " | "
         << setw(10) << fixed << std::setprecision(2) << amount << " | "
         << setww(7) << type << endl;
  }

class FinanceManager {
private:

