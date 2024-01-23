#pragma once
#include "linked_list.hpp"

template <class T> class Stack {
  SLList<T> *internal;

public:
  Stack() : internal(new SLList<T>()) {}

  bool is_empty() { return internal->is_empty(); }

  // using inserting front, because removing from front
  // is cheaper than removing from back,
  // (remember we need to move to prev item of tail)
  void push(T data) { internal->insert_front(data); }

  // in stack, it says,
  // remove item from the side it was inserted :)
  T pop() { return internal->remove_front(); }
};
