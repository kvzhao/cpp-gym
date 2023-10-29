/*
 * PQ with array implementation
 */

#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Key, typename Comparator = std::less<Key>>
class MyPriorityQueue {

public:
  MyPriorityQueue(){};

  void push(const Key &key) {

    elems.push_back(key);

    std::push_heap(elems.begin(), elems.end(), comp);
  }

  void pop() {
    if (!empty()) {
      std::pop_heap(elems.begin(), elems.end(), comp);
      elems.pop_back();
    }
  }

  Key top() const {

    if (!empty()) {
      return elems.front();
    }

    throw std::runtime_error("MyPriorityQueue is empty");
  }

  bool empty() const { return elems.empty(); }

  size_t size() const { return elems.size(); }

private:
  std::vector<Key> elems;
  Comparator comp;
};

int main(int argc, char *argv[]) {

  // suppose integer
  MyPriorityQueue<int> pq;

  std::string inp;
  while (std::getline(std::cin, inp)) {
    auto n = std::stoi(inp);
    pq.push(n);
    std::cout << n << " ";
  }
  std::cout << std::endl;

  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;

  return 0;
}
