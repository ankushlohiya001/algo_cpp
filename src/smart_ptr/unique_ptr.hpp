#pragma once

template <class T> struct default_deleter {
  void operator()(T *ref) { delete ref; }
};

template <class T, class D = default_deleter<T>> class unique_ptr {
  T *data_ptr;
  D deleter;

public:
  unique_ptr() {}
  unique_ptr(T *ptr) : data_ptr(ptr) {}
  unique_ptr(T *ptr, D del) : data_ptr(ptr), deleter(del) {}

  ~unique_ptr() {
    if (data_ptr != nullptr) {
      // to avoid deleting empty ptr
      deleter(data_ptr);
    }
  }

  void operator=(unique_ptr another) {
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

template <class T, class D, class... Args>
unique_ptr<T, D> make_unique(Args &&...args) {
  return unique_ptr(new T(args...), D());
}
