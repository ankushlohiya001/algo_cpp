#include "graph.hpp"
#include "queue.hpp"
#include <iostream>

int main() {
  std::cout << "-----------------" << std::endl;
  Graph g1(9);
  g1.add_edge_directed(1, 2);
  g1.add_edge_directed(1, 3);
  g1.add_edge_directed(1, 6);
  g1.add_edge_directed(3, 8);
  g1.add_edge_directed(3, 5);
  g1.add_edge_directed(3, 4);
  g1.add_edge_directed(4, 7);

  Queue<int> path;
  g1.dfs(1, &path);

  while (!path.is_empty()) {
    std::cout << path.deque() << "->";
  }
  std::cout << "\n-----------------" << std::endl;
  return 0;
}
