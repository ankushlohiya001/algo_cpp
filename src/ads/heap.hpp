#pragma once
#include <vector>

template <class T> void swap(T &ref_a, T &ref_b) {
  T tmp = ref_a;
  ref_a = ref_b;
  ref_b = tmp;
}

/*
 * Heap's abstract class
 * Currently limited to binary Heap.
 * Will switch to k-ary Heap, Soon :)
 * */
template <class T, class ST> class Heap {
protected:
  ST *store; // structure which manage indexed storage

  // to add new elements in store, it's just to add
  // element at one end of `store`,
  // movement is not managed by this fun.
  virtual void insert_at_last(T data) = 0;

  // function to specify how to access store's element,
  // ie. store[index], as it might not be possible for every
  // DS.
  virtual T &at(int index) = 0;

  // to access top element of heap,
  // either Min / Max (depends on data item)
  virtual T &top() { return at(0); };

  // similar to `insert_at_last`, but it's used to remove
  // element from `store`.
  virtual void remove_first() = 0;

  // to calcuate parent of any child node in heap
  // calculated mathematically :D
  inline static int parent_index(int child) {
    return (child + (child & 1)) / 2 - 1;
  }

  // function which decide the order of element,
  // or is used to find which pair of elements need to swap,
  // if this condition is not met, :)
  virtual bool is_parent(int parent_idx, int child_idx) = 0;

  // when an element is inserted at end (bottom of heap) of store,
  // then it need to move up, by following Heap's rule,
  // ie. is_parent,
  //
  // But due to reusabiltiy purposes, this function can also
  // able to move any index's element.
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

  // since removing an element for index based stores,
  // is not fast for either end,(usually front).
  //
  // so this function works by first swapping front to last,
  // and remove from last(usually fast)
  // and then moving down the newly front, since it's not it's
  // not it's correct position.
  //
  // compare to move up, move_down required more complex mech,
  // ie, need to decide for which child to swap with,
  //
  // performance is decreased directly for k-ary Heap.
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

public:
  Heap() : store(new ST) {}

  void insert(T data) {
    insert_at_last(data);
    // now move this value up to its' correct position
    move_up(len() - 1);
  }

  T remove_top() {
    T top = at(0);
    int ln = len();
    swap(at(0), at(ln - 1));
    remove_first();
    move_down(0);
    return top;
  }

  virtual int len() = 0;

  bool is_empty() { return len() == 0; }
};

template <class T> class MinHeap : public Heap<T, std::vector<T>> {
protected:
  std::vector<T> *store;

  T &at(int index) { return store->at(index); }

  bool is_parent(int parent_idx, int child_idx) {
    return at(parent_idx) < at(child_idx);
  }

  void insert_at_last(T data) { store->push_back(data); }

  void remove_first() { store->pop_back(); }

public:
  MinHeap() : store(new std::vector<T>) {}

  int len() { return store->size(); }
};

template <class T> class MaxHeap : public MinHeap<T> {
protected:
  bool is_parent(int parent_idx, int child_idx) {
    return this->at(parent_idx) > this->at(child_idx);
  }
};
