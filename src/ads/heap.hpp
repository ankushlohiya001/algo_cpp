#pragma once
#include <utility>
#include <vector>

template <class T, class ST> class Heap {
protected:
  ST *store;

public:
  Heap() : store(new ST) {}

  virtual void insert_at_last(T data) = 0;

  void insert(T data) {
    insert_at_last(data);
    // now move this value up to its' correct position
    move_up(len() - 1);
  }

  T remove_top() {
    T top = at(0);
    int ln = len();
    std::swap(at(0), at(ln - 1));
    remove_first();
    move_down(0);
    return top;
  }

  virtual int len() = 0;

  virtual T &at(int index) = 0;

  virtual T &top() { return at(0); };

  virtual T remove_first() = 0;

  inline static int parent_index(int child) {
    return (child + (child & 1)) / 2 - 1;
  }

  virtual bool is_parent(int parent_idx, int child_idx) = 0;

  void move_up(int index) {
    int child_idx = index;
    while (child_idx > 0) {
      int parent_idx = parent_index(child_idx);
      if (!is_parent(parent_idx, child_idx)) {
        std::swap(at(parent_idx), at(child_idx));
        child_idx = parent_idx;
      } else {
        break;
      }
    }
  }
};

template <class T> class MinHeap : public Heap<T, std::vector<T>> {
public:
  T &at(int index) {
    std::vector<T> *store = this->store;
    return store->at(index);
  }

  bool is_parent(int parent_idx, int child_idx) {
    return at(parent_idx) < at(child_idx);
  }

  void insert_at_last(T data) {
    std::vector<T> *store = this->store;
    store->push_back(data);
  }

  void remove_last() {
    std::vector<T> *store = this->store;
    store->pop_back();
  }
};
