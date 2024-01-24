#include "linear.hpp"
#include <iostream>

int main() {
  int *items = new int[]{1, 5, 34, 23, 123, 45};
  int index = linear_search(items, 37, 6);
  std::cout << index << std::endl;
  return 0;
}
