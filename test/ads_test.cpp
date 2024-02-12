#include "graph.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "-----------------" << std::endl;
  Graph g1(4, new char[]{'a', 'b', 'c', 'd'});
  g1.add_edge_directed('a', 'c');
  std::cout << g1.is_edge('a', 'c');
  std::cout << "\n-----------------" << std::endl;
  return 0;
}
