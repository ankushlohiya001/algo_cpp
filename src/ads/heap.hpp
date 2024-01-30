#pragma once
#include <utility>
#include <vector>

template <class T> void swap(T &ref_a, T &ref_b) {
  T tmp = ref_a;
  ref_a = ref_b;
  ref_b = tmp;
}

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
    T *top = at(0);
    int ln = len();
    std::swap(at(0), at(ln - 1));
    remove_first();
    move_down(0);
    return *top;
  }

  virtual int len() = 0;

  virtual T &at(int index) = 0;

  virtual T &top() { return at(0); };

  virtual void remove_first() = 0;

  inline static int parent_index(int child) {
    return (child + (child & 1)) / 2 - 1;
  }

  virtual bool is_parent(int parent_idx, int child_idx) = 0;

  void move_up(int index) {
    int child_idx = index;
    while (child_idx > 0) {
      int parent_idx = parent_index(child_idx);
      if (!is_parent(parent_idx, child_idx)) {
        swap(at(parent_idx), at(child_idx));
        child_idx = parent_idx;
      } else {
        break;
      }
    }
  }

  void move_down(int index) {
    int crnt_idx = index;
    while (true) {
      int a_idx = crnt_idx * 2 + 1; // left child index
      if (a_idx >= len())
        break;
      int b_idx = crnt_idx * 2 + 2; // right child index

      if (b_idx >= len()) {
        b_idx = a_idx;
      }
      int rare = crnt_idx;

      if (is_parent(a_idx, rare)) {
        rare = a_idx;
      }

      if (is_parent(b_idx, rare)) {
        rare = b_idx;
      }

      if (rare == crnt_idx) {
        break;
      } else {
        swap(at(rare), at(crnt_idx));
        crnt_idx = rare;
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

  int len() {
    std::vector<T> *store = this->store;
    return store->size();
  }

  bool is_parent(int parent_idx, int child_idx) {
    return at(parent_idx) < at(child_idx);
  }

  void insert_at_last(T data) {
    std::vector<T> *store = this->store;
    store->push_back(data);
  }

  void remove_first() {
    std::vector<T> *store = this->store;
    store->pop_back();
  }
};
