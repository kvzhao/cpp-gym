
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

int main(int argc, char *argv[]) {
  std::vector<std::string> args(argv, argv + argc);

  std::thread myThread{BackgroundTask()};

  myThread.join();

  return 0;
}
