#pragma once

template <class T> struct Node {
  T data;
  Node *left;
  Node *right;

public:
  Node(T dat) : data(dat), left(nullptr), right(nullptr) {}

  void insert(Node *node) {
    Node **dir;
    if (node->data < data) {
      dir = &left;
    } else {
      dir = &right;
    }
    if (*dir == nullptr) {
      *dir = node;
    } else {
      (*dir)->insert(node);
    }
  }
};

template <class T> struct BSTree {
  Node<T> *root;

public:
  BSTree() : root(nullptr) {}

  void insert(T data) {
    Node<T> *node = new Node<T>(data);
    if (root == nullptr) {
      root = node;
    } else {
      root->insert(node);
    }
  }

  T remove() {}
};
