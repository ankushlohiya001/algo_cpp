#include "queue.hpp"
#include <iostream>
#include <vector>

template <class T> class Print {
public:
  void operator()(T data) { std::cout << data << std::endl; }
};

int main() {
  std::cout << "-----------------" << std::endl;

  PQueue<int> *hp = new PQueue<int>();

  hp->enque(34, 10);
  hp->enque(37, 1);
  hp->enque(24, 3);

  std::cout << hp->peek() << std::endl;
  std::cout << "-----------------" << std::endl;
  return 0;
}
