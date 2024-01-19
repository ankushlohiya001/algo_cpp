#pragma once

template <class T> struct default_deleter {
  void operator()(T *ref) { delete ref; }
};

template <class T, class D = default_deleter<T>> class unique_ptr {
  T *data_ptr;
  D deleter;

public:
  unique_ptr() : data_ptr(nullptr) {}
  unique_ptr(T *ptr) : data_ptr(ptr) {}
  unique_ptr(T *ptr, D del) : data_ptr(ptr), deleter(del) {}

  ~unique_ptr() {
    if (data_ptr) {
      // to avoid deleting empty ptr
      deleter(data_ptr);
    }
  }

  // modifiers

  T *release() {
    // now caller is responsible for its management
    T *released = data_ptr;
    data_ptr = nullptr; // releasing reference to data_ptr
    return released;
  }

  void reset(T *new_ptr) {
    // deleting old ptr and replacing with new once
    if (data_ptr) {
      deleter(data_ptr);
    }
    data_ptr = new_ptr;
  }

  void swap(unique_ptr &other) {
    // simple swapping
    T *old_data_ptr = data_ptr;
    data_ptr = other.data_ptr;
    other.data_ptr = old_data_ptr;

    D old_deleter = deleter;
    deleter = other.deleter;
    other.deleter = old_deleter;
  }

  // observers
  T *get() const { return data_ptr; }

  D get_deleter() const { return deleter; }

  operator bool() const { return data_ptr != nullptr; }

  // object props accessing without `get`
  T operator*() const { return *data_ptr; }

  T *operator->() const { return data_ptr; }

  // indexed memory accessing
  T operator[](int v) { return data_ptr[v]; }

  void operator=(unique_ptr another) {
    // workaround to avoid copying pointer, which would otherwise
    // resulted in double pointer deleting, ie. deleting a ptr which
    // was deleted already
    // also used for reseting behaviour
    reset(another.data_ptr);
    another.data_ptr = nullptr;
  }

  // deleting copy constructor to avoid copying,
  // which would otherwise resulted in double ptr deleting.
  unique_ptr(const unique_ptr &) = delete;
};

template <class T, class... Args> unique_ptr<T> make_unique(Args &&...args) {
  return unique_ptr(new T(args...));
}

template <class T, class D, class... Args>
unique_ptr<T, D> make_unique(Args &&...args) {
  return unique_ptr(new T(args...), D());
}
