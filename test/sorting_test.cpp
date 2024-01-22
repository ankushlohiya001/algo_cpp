#include "insertion_sort.hpp"
/* #include "sorting.hpp" */
#include <iostream>

int main() {
  long *arr = new long[]{5, 2, 6, 3, 2, 0};

  insertion_sort<long>(arr, 6);

  for (int i = 0; i < 6; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return 0;
}
