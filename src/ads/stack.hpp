#pragma once
#include "linked_list.hpp"

/*
 * stack works on LIFO / FILO
 * means removing and inserting will be from same side.
 * of a list.
 * ie. a->b->c
 * here c was added last, so it'll be remove first
 * */
template <class T> class Stack {
  SLList<T> *internal;

public:
  Stack() : internal(new SLList<T>()) {}

  bool is_empty() { return internal->is_empty(); }

  T &peek() const {
    return internal->front(); // since we'll be pushing front
  }

  // using inserting front, because removing from front
  // is cheaper than removing from back,
  // (remember we need to move to prev item of tail)
  void push(T data) { internal->insert_front(data); }

  // in stack, it says,
  // remove item from the side it was inserted :)
  T pop() { return internal->remove_front(); }
};
