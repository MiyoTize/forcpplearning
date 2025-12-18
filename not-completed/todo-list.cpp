#include <iostream>
#include <algorithm>
#include <vector>
using std::string, std::vector, std::cout, std::cin, std::endl;

class Task {
private:
  string description;
  int priority;
  bool completed;

public:
  Task(string desc, int prio) : description(desc), priority(prio), completed(false) {}

  string getDescription() const { return description; }
  int getPriority() const { return priority; }
  bool isCompleted() const { return completed; }

  void markCompleted() { completed = true; }
  void setPriority(int prio) { priority = prio; }
 
  bool operator<(const Task& other) const {
    return priority > other.priority;
  }
};

class TodoList {
private:
  vector<Task> tasks;

public:
  void addTask(const string& desc, int priority) {
    tasks.emplace_back(desc, priority);
    std::sort(tasks.begin(), tasks.end());
  }

  void showTasks() const {
    cout << "\n=== YOURS TASKS ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
      cout << (i + 1) << ". ";
      if (tasks[i].isCompleted()) cout << "[#] ";
      else cout << "[ ] ";
      cout << tasks[i].getDescription()
           << "\npriority: " << tasks[i].getPriority();
    }
  }

  void completeTask(int index) {
    if (index >= 1 && index <= tasks.size()) {
    tasks[index - 1].markCompleted();
    }
  }

  void showStats() const {
    int total = tasks.size();
    int completed = 0;
    int highPriority = 0;

    for (const auto& task : tasks) {
      if (task.isCompleted()) ++completed;
      if (task.getPriority() >= 4) ++highPriority;
    }

    cout << "\n=== STATISTICS ==="
         << "\nTotal tasks: " << total  
         << "\nDone: " << completed
         << "\nHigh priority: " << highPriority
         << "\nProgress: " << (total > 0 ? (completed * 100 / total) : 0);
  }
};

int main()
{/*Yo here Miyo!:?*/
  TodoList myList;

  myList.addTask("kill myself", 4);
  myList.addTask("learn chemistry", -1);
  myList.addTask("LiveUSB", 1);

  myList.showTasks();
  myList.completeTask(1);
  myList.showStats();
};
