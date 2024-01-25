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

  bool remove(Node *node) {
    Node<T> **target;
    if (node->data < data) {
      target = &left;
    } else {
      target = &right;
    }

    if (*target == nullptr) {
      return false;
    } else if ((*target)->data == node->data) {
      Node *left = (*target)->left;
      *target = (*target)->right;
      if (*target == nullptr) {
        *target = left;
        left = nullptr;
      } else {
        (*target)->insert(left);
      }
      return true;
    } else {
      return (*target)->remove(node);
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

  bool remove(T data) {
    if (root == nullptr) {
      return false;
    } else if (root->data == data) {
      Node<T> *right = root->right;
      root = root->left;
      if (root == nullptr) {
        root = right;
      } else {
        root->insert(right);
      }
      return true;
    } else {
      return root->remove(new Node<T>(data));
    }
  }

  template <class FN> static void in_order(Node<T> *node, FN *fn) {
    if (node->left != nullptr) {
      BSTree::in_order(node->left, fn);
    }
    (*fn)(node->data);
    if (node->right != nullptr) {
      BSTree::in_order(node->right, fn);
    }
  }
  template <class FN> void in_order(FN *fn) { BSTree::in_order(root, fn); }

  template <class FN> static void pre_order(Node<T> *node, FN *fn) {
    (*fn)(node->data);
    if (node->left != nullptr) {
      BSTree::pre_order(node->left, fn);
    }
    if (node->right != nullptr) {
      BSTree::pre_order(node->right, fn);
    }
  }
  template <class FN> void pre_order(FN *fn) { BSTree::pre_order(root, fn); }

  template <class FN> static void post_order(Node<T> *node, FN *fn) {
    if (node->left != nullptr) {
      BSTree::post_order(node->left, fn);
    }
    if (node->right != nullptr) {
      BSTree::post_order(node->right, fn);
    }
    (*fn)(node->data);
  }
  template <class FN> void post_order(FN *fn) { BSTree::post_order(root, fn); }
};
