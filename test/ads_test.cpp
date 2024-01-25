#include "binary_tree.hpp"
#include <iostream>

template <class T> class Print {
public:
  void operator()(T data) { std::cout << data << std::endl; }
};

int main() {
  BSTree<int> t1;
  t1.insert(37);
  t1.insert(34);
  t1.insert(38);
  t1.insert(24);
  t1.insert(14);
  t1.insert(57);
  t1.in_order(new Print<int>);
  std::cout << "-----------------" << std::endl;
  t1.pre_order(new Print<int>);
  std::cout << "-----------------" << std::endl;
  t1.post_order(new Print<int>);
  return 0;
}
