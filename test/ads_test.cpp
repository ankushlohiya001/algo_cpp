#include "linked_list.hpp"
#include <iostream>

int main() {
  SLList<int> l1;
  l1.insert_back(34);
  l1.insert_back(37);
  l1.insert_back(32);
  l1.insert_back(38);

  /* while (!l1.is_empty()) { */
  /*   std::cout << l1.remove_back() << std::endl; */
  /* } */
  std::cout << l1.size() << std::endl;
  return 0;
}
