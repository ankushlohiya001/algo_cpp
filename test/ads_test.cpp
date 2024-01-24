#include "binary_tree.hpp"
#include <iostream>

int main() {

  BSTree<int> t1;
  t1.insert(37);
  t1.insert(34);
  t1.insert(38);
  std::cout << t1.root->right->data << std::endl;
  return 0;
}
