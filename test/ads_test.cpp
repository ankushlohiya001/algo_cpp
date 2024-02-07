#include "linked_list.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "-----------------" << std::endl;
  LinkedList<int, SItem<int>> *sl = new SLList<int>();
  SLList<int> *ls = static_cast<SLList<int> *>(sl);
  ls->insert_item_at(0, new SItem<int>(34));
  ls->insert_item_at(1, new SItem<int>(37));
  std::cout << ls->head->next->data << std::endl;

  /* while (!sl->is_empty()) { */
  /*   std::cout << sl->remove_front() << ", "; */
  /* } */
  std::cout << "-----------------" << std::endl;
  return 0;
}
