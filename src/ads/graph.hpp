#pragma once
#include "queue.hpp"
#include "stack.hpp"
#include <unordered_map>
#include <unordered_set>

template <class T> inline T min(T a, T b) { return a < b ? a : b; }

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
    int row = get_vertex_index(vert_a);
    int col = get_vertex_index(vert_b);
    return rc_to_ind(row, col, vert_count);
  }

  inline int get_vertex_index(V vert) { return vertices->at(vert); }

  inline V vertex_at(int index) { return vert_names[index]; }

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
    int cost = edge_cost(from, to);
    return !!cost;
  }

  int edge_cost(V from, V to) {
    int index = get_edge_index(from, to);
    return matrix[index];
  }

  int vertex_connections(V from, Queue<V> *connections) {
    int count = 0;

    for (int i = 0; i < vert_count; i++) {
      V to = vertex_at(i);
      if (is_edge(from, to)) {
        connections->enque(to);
        count++;
      }
    }

    return count;
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
    std::unordered_set<V> visited;
    Stack<V> book;
    book.push(init); // vertex's index
    while (!book.is_empty()) {
      V crnt = book.pop();
      if (visited.count(crnt) > 0) {
        continue;
      }
      visited.insert(crnt);

      Queue<V> connections;
      vertex_connections(crnt, &connections);
      while (!connections.is_empty()) {
        V vertex = connections.deque();
        if (visited.count(vertex) == 0) {
          book.push(vertex);
        }
      }

      road.enque(crnt);
    }
    *path = road;
  }

  // visits node's every child, then visit grand child and so on.
  void bfs(V init, Queue<V> *path) {
    Queue<V> road;
    std::unordered_set<V> visited;
    Queue<V> book;
    book.enque(init); // vertex's index
    while (!book.is_empty()) {
      V crnt = book.deque();
      if (visited.count(crnt) > 0) {
        continue;
      }
      visited.insert(crnt);

      Queue<V> connections;
      vertex_connections(crnt, &connections);
      while (!connections.is_empty()) {
        V vertex = connections.deque();
        if (visited.count(vertex) == 0) {
          book.enque(vertex);
        }
      }

      road.enque(crnt);
    }
    *path = road;
  }

  // dijkstra's algo for finding shortest path between
  // two vertices. it finds best(shortest) path
  int dijkstra_path(V from, V to, Stack<V> *path) {
    int INF = 100000000;
    // don't know, but works :))
    int *weights = new int[vert_count];
    fill(weights, vert_count, INF);

    int *short_from = new int[vert_count]; // who come from

    std::unordered_set<V> unvisited;
    for (int i = 0; i < vert_count; i++) {
      V vertex = vert_names[i];
      unvisited.insert(vertex);
    }

    V crnt = from;
    int last_min_cost = 0;
    while (unvisited.size() > 1) {

      unvisited.erase(crnt);
      Queue<V> connections;
      vertex_connections(crnt, &connections);

      while (!connections.is_empty()) {
        V conn = connections.deque();
        int vert_ind = get_vertex_index(conn);
        int conn_cost = last_min_cost + edge_cost(crnt, conn);

        if (conn_cost < weights[vert_ind]) {
          weights[vert_ind] = conn_cost;

          short_from[vert_ind] = get_vertex_index(crnt);
        }
      }

      int crnt_min_cost = INF;
      for (auto vert_ref = unvisited.begin(); vert_ref != unvisited.end();) {
        V vert = *vert_ref;
        int index = get_vertex_index(vert);
        if (weights[index] >= last_min_cost && weights[index] < crnt_min_cost) {
          crnt_min_cost = weights[index];
          crnt = vert;
        }
        vert_ref++;
      }
      last_min_cost = crnt_min_cost;
    }

    path->push(to);

    V ptr_at = to;
    while (ptr_at != from) {
      int vert_idx = get_vertex_index(ptr_at);
      ptr_at = vertex_at(short_from[vert_idx]);
      path->push(ptr_at);
    }

    return weights[get_vertex_index(to)];
  }

  // a* algo for path finding between two vertices.
  // works for uniform grid based graph..
  // so might not implement for now.
  void astar_path(V from, V to, Queue<V> *path);
};
