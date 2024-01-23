#include "stack.hpp"
#include <iostream>

int main() {

  Stack<int> t1;
  t1.push(34);
  t1.push(37);
  while (!t1.is_empty()) {
    std::cout << t1.pop() << std::endl;
  }
  return 0;
}
