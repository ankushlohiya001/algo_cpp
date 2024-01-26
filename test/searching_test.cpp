#include "binary.hpp"
#include "insertion_sort.hpp"
#include <iostream>

int main() {
  int *items = new int[]{1, 5, 34, 23, 123, 45};
  binary_insertion_sort(items, 6); // 1 5 23 34 45 123
  for (int i = 0; i < 6; i++) {
    std::cout << items[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}
