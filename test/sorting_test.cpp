/* #include "sorting.hpp" */
#include "merge_sort.hpp"
#include <iostream>

int main() {
  long arr[] = {1, 3, 2, 0, 4, 3, 5, 1};

  int len = sizeof(arr) / sizeof(long);

  merge_sort<long>(arr, len);

  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "\n";
  return 0;
}
/*

1 3 2, 0 4 3 5

1 3, 2 0, 4 3, 5 1
1 3, 0 2, 3 4, 1 5
0 1 2 3, 1 3 4 5

0 1 1 2 3 3 4 5

*/
