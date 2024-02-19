#include "linked_list.hpp"
#include <iostream>

int main() {
  std::cout << "-----------------" << std::endl;

  CLList<int> clist;
  clist.insert_back(34);
  clist.insert_back(87);
  clist.insert_front(56);

  clist.insert_front(32);

  clist.remove_front();
  clist.remove_front();
  /* clist.remove_back(); */

  SItem<int> *crnt = clist.head;
  for (int i = 0; i < 10; i++) {
    std::cout << crnt->get_data() << ", ";
    crnt = crnt->next;
  }
  /* std::cout << clist.head->next->next->get_data(); */

  /* while (!clist.is_empty()) { */
  /**/
  /* } */

  std::cout << "\n-----------------" << std::endl;
  return 0;
}

/* (h, a, b, c, h, a, b...) */
