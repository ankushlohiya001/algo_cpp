#include "trie.hpp"
#include <iostream>

int main() {
  std::cout << "-----------------" << std::endl;

  Trie t1;
  t1.insert("ankush");
  t1.insert("ankit");
  /* t1.insert("akram"); */

  std::cout << t1.root.next->at('a').next->count('k') << std::endl;

  /* std::cout << t1.search("akr") << std::endl; */
  /* std::cout << t1.search("anil") << std::endl; */

  std::cout << "\n-----------------" << std::endl;
  return 0;
}

/* (h, a, b, c, h, a, b...) */
