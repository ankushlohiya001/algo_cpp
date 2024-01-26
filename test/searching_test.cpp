#include "binary.hpp"
#include "insertion_sort.hpp"
#include <iostream>

int main() {
  int *items = new int[]{1, 5, 34, 23, 123, 45};
  insertion_sort(items, 6); // 1 5 23 34 45 123
  int index = binary_search(items, 37, 6);
  std::cout << index << std::endl;
  return 0;
}
