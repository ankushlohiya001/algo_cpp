#include "heap.hpp"
#include <iostream>
#include <vector>

template <class T> class Print {
public:
  void operator()(T data) { std::cout << data << std::endl; }
};

int main() {
  std::cout << "-----------------" << std::endl;

  Heap<int, std::vector<int>> *hp = new MinHeap<int>();

  hp->insert(34);
  hp->insert(32);
  hp->insert(37);
  hp->insert(51);
  hp->insert(24);

  for (int i = 0; i < 5; i++) {
    std::cout << hp->at(i) << std::endl;
  }

  std::cout << "-----------------" << std::endl;
  return 0;
}
