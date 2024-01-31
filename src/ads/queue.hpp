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

template <class T> struct PItem {
  T data;
  int priority;
};

// priority queue using heap
template <class T>
class PQueue : private Heap<PItem<T>, std::vector<PItem<T>>> {
private:
  std::vector<PItem<T>> *store;
  PItem<T> &at(int index) { return store->at(index); }
  bool is_parent(int parent_idx, int child_idx) {
    return at(parent_idx).priority < at(child_idx).priority;
  }

  void insert_at_last(PItem<T> data) { store->push_back(data); }

  void remove_first() { store->pop_back(); }

public:
  PQueue() : store(new std::vector<PItem<T>>) {}
  int len() { return store->size(); }

  T &peek() { return this->top().data; }

  void enque(T data, int priority) { this->insert(PItem<T>{data, priority}); }

  T deque() { return this->remove_top().data; }
};
