#pragma once
#include "linked_list.hpp"

/*
 * simple Queue works on FIFO / LILO
 * means removing and inserting will be from differnt side
 * ie. a->b->c
 * here c was added last, but it'll be removed last.
 * */

template <class T> class Queue {
  SLList<T> *internal;

public:
  Queue() : internal(new SLList<T>()) {}

  bool is_empty() { return internal->is_empty(); }

  T &peek() const { return internal->front(); }

  // since for single linked_list:
  // removing from last required n iterations.
  // but we've cheaper alternative
  // ie. removing front, adding last, :))

  void enque(T data) { internal->insert_back(data); }

  T deque() { return internal->remove_front(); }
};
