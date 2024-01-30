#pragma once
#include "heap.hpp"
#include "linked_list.hpp"
#include <vector>

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

// priority queue using heap
template <class T> class PQueue : public Heap<T, std::vector<T>> {
private:
  std::vector<T> *store;
  T &at(int index) { return store->at(index); }
  bool is_parent(int parent_idx, int child_idx) {
    return at(parent_idx) < at(child_idx);
  }

  void insert_at_last(T data) { store->push_back(data); }

  void remove_first() { store->pop_back(); }

public:
  PQueue() : store(new std::vector<T>) {}
  int len() { return store->size(); }
};
