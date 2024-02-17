#pragma once
#include "queue.hpp"
#include "stack.hpp"
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

template <class T> T min(T a, T b) { return a < b ? a : b; }

template <class T> void fill(T *arr, int length, T val) {
  for (int i = 0; i < length; i++) {
    arr[i] = val;
  }
}

int rc_to_ind(int row, int col, int cols) { return row * cols + col; }

void ind_to_rc(int ind, int cols, int *row, int *col) {
  *row = ind / cols;
  *col = ind % cols;
}

template <class V = int> class Graph {
  int vert_count;
  int *matrix;
  std::unordered_map<V, int> *vertices;
  V *vert_names;

  int get_edge_index(V vert_a, V vert_b) {
    int row = vertices->at(vert_a);
    int col = vertices->at(vert_b);
    return rc_to_ind(row, col, vert_count);
  }

public:
  Graph(int v_c)
      : vert_count(v_c), matrix(new int[v_c * v_c]),
        vertices(new std::unordered_map<int, int>()), vert_names(new int[v_c]) {
    for (int i = 0; i < v_c; i++) {
      vertices->insert_or_assign(i, i);
      vert_names[i] = i;
    }
  }

  Graph(int v_c, V *vert)
      : vert_count(v_c), matrix(new int[v_c * v_c]),
        vertices(new std::unordered_map<V, int>), vert_names(new V[v_c]) {

    for (int i = 0; i < v_c; i++) {
      vertices->insert_or_assign(vert[i], i);
      vert_names[i] = vert[i];
    }
  }

  bool is_edge(V from, V to) {
    int index = get_edge_index(from, to);
    return !!matrix[index];
  }

  bool add_edge_directed(V from, V to, int weight) {
    int index = get_edge_index(from, to);
    if (!is_edge(from, to)) {
      matrix[index] = weight;
      return true;
    } else {
      return false;
    }
  }

  bool add_edge_directed(V from, V to) {
    return add_edge_directed(from, to, 1);
  }

  bool add_edge(V vert_a, V vert_b, int weight) {
    bool res = add_edge_directed(vert_a, vert_b, weight);
    bool res2 = add_edge_directed(vert_b, vert_a, weight);
    return res && res2;
  }

  bool add_edge(V vert_a, V vert_b) { return add_edge(vert_a, vert_b, 1); }

  bool remove_edge_directed(V from, V to) {
    if (!is_edge(from, to)) {
      int index = get_edge_index(from, to);
      matrix[index] = 1;
      return true;
    } else {
      return false;
    }
  }

  bool remove_edge(V vert_a, V vert_b) {
    bool res = remove_edge_directed(vert_a, vert_b);
    bool res2 = remove_edge_directed(vert_b, vert_a);
    return res && res2;
  }

  // visits node to dead end, then visit next child.
  void dfs(V init, Queue<V> *path) {
    Queue<V> road;
    Stack<int> book;
    book.push(vertices->at(init)); // vertex's index
    while (!book.is_empty()) {
      int crnt = book.pop();
      for (int i = 0; i < vert_count; i++) {
        if (i == crnt)
          continue;
        int index = rc_to_ind(crnt, i, vert_count);
        if (matrix[index] != 0) {
          book.push(i);
        }
      }
      road.enque(vert_names[crnt]);
    }
    *path = road;
  }

  // visits all childs, then visits thier childs and so on...
  void bfs(V init, Queue<V> *path) {
    Queue<V> road;
    Queue<int> book;
    book.enque(vertices->at(init)); // vertex's index
    while (!book.is_empty()) {
      int crnt = book.deque();
      for (int i = 0; i < vert_count; i++) {
        if (i == crnt)
          continue;
        int index = rc_to_ind(crnt, i, vert_count);
        if (matrix[index] != 0) {
          book.enque(i);
        }
      }
      road.enque(vert_names[crnt]);
    }
    *path = road;
  }

  // dijkstra's algo for finding shortest path between
  // two vertices. it finds optimal path
  void dijkstra_path(V from, V to, Queue<V> *path) {
    // don't know, but works :))
    int *weights = new int[vert_count];
    fill(weights, vert_count, 99999999);

    std::unordered_map<int, bool> visited;
    path->enque(from);

    int crnt = from;
    int cost = 0;
    while (crnt != -1) {
      int crnt_min_cost = 99999999;
      int next = -1;
      visited.insert_or_assign(crnt, 1);
      for (int i = 0; i < vert_count; i++) {
        if (visited.count(i) > 0)
          continue;
        if (is_edge(crnt, i)) {
          int i_cost = cost + rc_to_ind(crnt, i, vert_count);
          int crnt_cost = min(weights[i], i_cost);
          if (crnt_cost < crnt_min_cost && weights[i] != crnt_cost) {
            crnt_min_cost = crnt_cost;
            next = i;
            path->enque(vert_names[i]);
          }
          weights[i] = crnt_cost;
        }
      }
      crnt = next;
      cost += crnt_min_cost;
    }
  }

  // a* algo for path finding between two vertices.
  void astar_path(V from, V to, Queue<V> *path);
};
