/* #include "sorting.hpp" */
#include "heap_sort.hpp"
#include <iostream>

int main() {
  long arr[] = {1, 3, 2, 0, 4, 3, 5, 1};

  int len = sizeof(arr) / sizeof(long);

  heap_sort<long>(arr, len);

  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return 0;
}
