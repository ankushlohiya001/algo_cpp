#include "graph.hpp"
#include "queue.hpp"
#include <iostream>

int main() {
  std::cout << "-----------------" << std::endl;

  Graph<char> graph(8, new char[]{'h', 'a', 'b', 'c', 'd', 'e', 'f', 's'});

  graph.add_edge('h', 'a', 3);
  graph.add_edge('h', 'c', 5);
  graph.add_edge('h', 'b', 2);
  graph.add_edge('a', 'd', 3);
  graph.add_edge('b', 'd', 1);
  graph.add_edge('b', 'e', 6);
  graph.add_edge('c', 'e', 2);
  graph.add_edge('d', 'f', 4);
  graph.add_edge('e', 'f', 1);
  graph.add_edge('e', 's', 4);
  graph.add_edge('f', 's', 2);

  Queue<char> path;

  graph.bfs('h', &path);

  while (!path.is_empty()) {
    std::cout << path.deque() << ", ";
  }

  std::cout << "\n-----------------" << std::endl;
  return 0;
}

/* (h, a, b, c, h, a, b...) */
