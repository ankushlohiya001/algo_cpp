#pragma once
#include <utility>
#include <vector>

template <class T, class ST> class Heap {
protected:
public:
  ST *store;
  Heap() : store(new ST) {}

  virtual void insert_at_last(T data) = 0;

  void insert(T data) {
    insert_at_last(data);
    // now move this value up to its' correct position
    move_up(store->size() - 1);
  }

  virtual T &top() { return (*store)[0]; };

  virtual T remove() = 0;

  inline static int parent_index(int child) {
    return (child + (child & 1)) / 2 - 1;
  }

  virtual bool is_parent(int parent_idx, int child_idx) = 0;

  virtual void move_up(int index) {
    int child_idx = index;
    while (child_idx > 0) {
      int parent_idx = parent_index(child_idx);
      if (!is_parent(parent_idx, child_idx)) {
        std::swap(store->at(parent_idx), store->at(child_idx));
        child_idx = parent_idx;
      } else {
        break;
      }
    }
  }
};

template <class T> class MinHeap : public Heap<T, std::vector<T>> {
public:
  bool is_parent(int parent_idx, int child_idx) {
    std::vector<T> *store = this->store;
    return store->at(parent_idx) < store->at(child_idx);
  }

  void insert_at_last(T data) {
    std::vector<T> *store = this->store;
    store->push_back(data);
  }

  T remove() {
    std::vector<T> *store = this->store;
    T top = store->at(0);
    /// will just swap first and last
    store[0] = store[store->size() - 1];
    // then removing last
    store->pop_back();
    // now we need to move new top element down to its' correct position
    return top;
  }
};
