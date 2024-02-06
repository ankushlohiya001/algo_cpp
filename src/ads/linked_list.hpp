#pragma once
#include <stdexcept>

template <class T> struct Item {
  T data;
  virtual T get_data() { return data; }
};

template <class T, class IT = Item<T>> class LinkedList {
protected:
  // linked list
  long count;

  virtual IT *item_at(int index) = 0;

  virtual void insert_item_at(int index, IT *item) = 0;

  // will be called after bound check, so
  // will always guarntee that element will found
  virtual IT *remove_item_from(int index) = 0;

public:
  LinkedList() : count(0) {}

  virtual int size() { return count; } // maybe implementer do this self

  bool is_empty() {
    // helpfull for checking list before removing :))
    return size() == 0;
  }

  T &front() const { return item_at(0)->get_data(); }

  void insert_front(T data) {
    IT *item = new IT(data);
    insert_item_at(0, item); // implementer's insertion
    count++;
  }

  T remove_front() {
    if (is_empty()) {
      throw std::underflow_error("empty stack");
    } else {
      IT *old_front = remove_item_from(0);
      count--;

      T data = old_front->get_data();
      delete old_front;
      return data;
    }
  }

  T &back() const { return item_at(size() - 1)->get_data(); }

  void insert_back(T data) {
    insert_item_at(size(), data);
    count++;
  }

  T remove_back() {
    if (is_empty()) {
      throw std::underflow_error("empty stack");
    } else {
      IT *old_back = remove_item_from(size() - 1);
      count--;
      T data = old_back->get_data();
      delete old_back;
      return data;
    }
  }
};

template <class T> struct SItem {
  T data;
  SItem *next;
};

template <class T> class SLList : private LinkedList<T, SItem<T>> {
  SItem<T> *head;
  SItem<T> *tail;

  SItem<T> *item_at(int index) {
    int len = this->size();
    SItem<T> *ref = nullptr;
    int i = 0;
    while (ref != nullptr && i < len) {
      if (i == index) {
        break;
      } else {
        ref = ref->next;
        i++;
      }
    }
    return ref;
  }

  void insert_item_at(int index, SItem<T> *item) {}

  SItem<T> *remove_item_from(int index) {}
};
