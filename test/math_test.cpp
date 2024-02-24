#include "math.hpp"
#include <iostream>

int main() {
  std::cout << "--------------------\n";

  double *arr = new double[]{3, 5, 7, 1};

  double mn = average(arr, 4);
  std::cout << mn;
  std::cout << "\n--------------------\n";
  return 0;
}
