#pragma once
#include <vector>

template <class T, class ST> class Heap {
  ST *store;

public:
  Heap() : store(new ST) {}
  virtual void insert(T data) = 0;

  virtual T &top() { return store[0]; };

  virtual T remove() = 0;
};

template <class T> class MinHeap : Heap<T, std::vector<T>> {
public:
  void insert(T data) {
    std::vector<T> *store = this->store;
    store->push_back(data);
    // now move this value up to its' correct position
  }

  T remove() {
    std::vector<T> *store = this->store;
    T top = store[0];
    /// will just swap first and last
    store[0] = store[store->size() - 1];
    // then removing last
    store->pop_back();
    // now we need to move new top element down to its' correct position
    return top;
  }
};
