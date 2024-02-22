#pragma once
#include <string>
#include <unordered_map>

struct Node {
  std::unordered_map<char, Node> *next;
  Node() : next(new std::unordered_map<char, Node>()) {}
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
      auto ct = crnt->next;
      if (ct->count(chr) == 0) {
        ct->insert_or_assign(chr, Node());
      } else {
        crnt = &ct->at(chr);
      }
    }
  }

  bool search(std::string word) {
    Node *crnt = &root;
    for (auto chr : word) {
      auto ct = crnt->next;
      if (ct->count(chr) == 0) {
        return false;
      } else {
        crnt = &ct->at(chr);
      }
    }
    return true;
  }
};
