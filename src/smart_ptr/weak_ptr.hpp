#pragma once

template <class T> class weak_ptr {
  T *data_ptr;

public:
  // modifiers
  void reset() {
    // releases the ownership of the managed ptr
  }

  void swap(weak_ptr &other) {
    // just swapping
  }

  // observers
  long use_count() const {
    // return no of refs count
  }

  bool expired() const {
    // to verify whether ptr is still valid(alive)
  }
};
