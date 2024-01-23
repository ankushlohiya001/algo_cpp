#include "linked_list.hpp"
#include <iostream>

int main() {
  SLList<int> l1;
  l1.insert_back(34);
  l1.insert_back(37);

  while (!l1.is_empty()) {
    std::cout << l1.remove_back() << std::endl;
  }
  return 0;
}
