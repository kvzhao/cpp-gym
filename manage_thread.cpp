
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

void hello() { std::cout << "Hello Concurrent World!\n"; }

class BackgroundTask {
public:
  void operator()() const { hello(); }
};

struct task {
  int &_data;

  task(int &data) : _data(data) {}

  void operator()() {
    _data++;
    std::cout << "data is " << _data << std::endl;
  }
};

// RAII
class ThreadGuard {
  std::thread &_t;

public:
  explicit ThreadGuard(std::thread &t) : _t(t) {}

  ~ThreadGuard() {
    if (_t.joinable())
      _t.join();
  }

  ThreadGuard(ThreadGuard const &) = delete;
  ThreadGuard &operator=(ThreadGuard const &) = delete;
};

int main(int argc, char *argv[]) {
  std::vector<std::string> args(argv, argv + argc);

  int data = 0;

  if (args.size() == 2) {
      data = std::stoi(args[1]);
  }

  task myTask(data);

  std::thread myThread(myTask);

  ThreadGuard g(myThread);

  return 0;
}
