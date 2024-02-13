#pragma once
#include <unordered_map>

int rc_to_ind(int row, int col, int cols) { return row * cols + col; }

void ind_to_rc(int ind, int cols, int *row, int *col) {
  *row = ind / cols;
  *col = ind % cols;
}

template <class V = int> class Graph {
  int vert_count;
  int *matrix;
  std::unordered_map<V, int> *vertices;

  int get_edge_index(V vert_a, V vert_b) {
    int row = vertices->at(vert_a);
    int col = vertices->at(vert_b);
    return rc_to_ind(row, col, vert_count);
  }

public:
  Graph(int v_c)
      : vert_count(v_c), matrix(new int[v_c * v_c]),
        vertices(new std::unordered_map<int, int>()) {
    for (int i = 0; i < v_c; i++) {
      vertices->insert(i, i);
    }
  }

  Graph(int v_c, V *vert)
      : vert_count(v_c), matrix(new int[v_c * v_c]),
        vertices(new std::unordered_map<V, int>) {

    for (int i = 0; i < v_c; i++) {
      vertices->insert_or_assign(vert[i], i);
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
};
