#include "linked_list.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "-----------------" << std::endl;
  LinkedList<char, DItem<char>> *sl = new DLList<char>();
  /* SLList<char> *ls = static_cast<SLList<char> *>(sl); */
  // a->b->e->c->d
  sl->insert_back('e');
  sl->insert_back('c');
  sl->insert_front('b');
  sl->insert_back('d');
  sl->insert_front('a');

  sl->remove_back();
  sl->remove_front();
  sl->remove_front();

  std::cout << sl->front() << std::endl;
  std::cout << sl->back() << std::endl;

  while (!sl->is_empty()) {
    std::cout << sl->remove_front() << "->";
  }
  std::cout << "nullptr\n";
  std::cout << "-----------------" << std::endl;
  return 0;
}
