#pragma once

template <class T> class unique_ptr {
  T *data_ptr;

public:
  unique_ptr() {}
  unique_ptr(T *ptr) : data_ptr(ptr) {}

  ~unique_ptr() {
    if (data_ptr != nullptr) {
      // to avoid deleting empty ptr
      delete data_ptr;
    }
  }

  void operator=(unique_ptr<T> another) {
    // workaround to avoid copying pointer, which would otherwise
    // resulted in dual pointer deleting, ie. deleting a ptr which
    // was deleted already
    data_ptr = another.data_ptr;
    another.data_ptr = nullptr;
  }
};

template <class T, class... Args> unique_ptr<T> make_unique(Args &&...args) {
  return unique_ptr(new T(args...));
}
