#include "linked_list.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "-----------------" << std::endl;
  LinkedList<char, DItem<char>> *sl = new DLList<char>();
  DLList<char> *ls = static_cast<DLList<char> *>(sl);
  // a,b,e,c,d
  sl->insert_front('e');
  sl->insert_back('c');
  sl->insert_front('b');
  sl->insert_back('d');
  sl->insert_front('a');

  /* std::cout << ls->remove_item_from(4)->get_data() << std::endl; */
  /**/
  /* DItem<char> *walker = ls->head; */
  /* while (walker != nullptr) { */
  /*   std::cout << walker->get_data() << ", "; */
  /*   walker = walker->next; */
  /* } */
  /* std::cout << ls->tail->data << std::endl; */

  std::cout << sl->front() << std::endl;
  std::cout << sl->back() << std::endl;

  /* for (int i = 0; i < sl->size(); i++) { */
  /*   std::cout << ls->item_at(i)->get_data() << ", "; */
  /* } */

  /* while (!sl->is_empty()) { */
  /*   std::cout << sl->remove_front() << "->"; */
  /* } */
  /* std::cout << "nullptr\n"; */
  std::cout << "\n-----------------" << std::endl;
  return 0;
}
