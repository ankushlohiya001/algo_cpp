#pragma once
#include <string>

const int SYMBOL_CAP = 256;

struct Node {
  Node *connections[SYMBOL_CAP]; // Node *
  Node() {
    for (int i = 0; i < SYMBOL_CAP; i++) {
      connections[i] = nullptr;
    }
  }
};

// trie data structure useful for string matching,
// usually lot faster than others :)
class Trie {

public:
  Node root;

  Trie() : root({Node()}) {}

  void insert(std::string word) {
    Node *crnt = &root;
    for (auto chr : word) {
      auto conns = crnt->connections;
      if (!conns[chr]) {
        conns[chr] = new Node();
      }
      crnt = conns[chr];
    }
  }

  bool search(std::string word) {
    Node *crnt = &root;
    for (auto chr : word) {
      auto conns = crnt->connections;
      if (!conns[chr]) {
        return false;
      } else {
        crnt = conns[chr];
      }
    }
    return true;
  }
};
