#include "trie.hpp"
#include <iostream>

int main() {
  std::cout << "-----------------" << std::endl;

  Trie t1;
  t1.insert("ankush");
  t1.insert("ankit");
  t1.insert("akram");
  t1.insert("surender");

  std::cout << t1.search("akram") << std::endl;
  std::cout << t1.search("surek") << std::endl;

  std::cout << "\n-----------------" << std::endl;
  return 0;
}
