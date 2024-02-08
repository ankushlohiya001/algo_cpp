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

  T front() {
    IT *item = item_at(0);
    return item->get_data();
  }

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

  T back() {
    IT *item = item_at(size() - 1);
    return item->get_data();
  }

  void insert_back(T data) {
    IT *item = new IT(data);
    insert_item_at(this->size(), item);
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
  SItem(T dat) : data(dat), next(nullptr) {}
  T get_data() { return data; }
};

template <class T> class SLList : public LinkedList<T, SItem<T>> {
public:
  SItem<T> *head;
  SItem<T> *tail;

  SItem<T> *item_at(int index) {
    int len = this->size();
    SItem<T> *ref = head;
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

  void insert_item_at(int index, SItem<T> *item) {
    if (head == nullptr) {
      head = tail = item;
    } else if (index >= this->size()) {
      tail->next = item;
      tail = item;
    } else {
      SItem<T> **target = &head;
      for (int i = 0; (*target != nullptr) && i < index; i++) {
        target = &((*target)->next);
      }
      if (*target != nullptr) {
        item->next = *target;
      }
      *target = item;
    }
  }

  /* a->b->c->d */

  SItem<T> *remove_item_from(int index) {
    if (head == nullptr) {
      return nullptr;
    } else if (index == 0) {
      SItem<T> *old = head;
      head = old->next;
      return old;
    } else {
      SItem<T> **target = &head;
      for (int i = 0; (*target != nullptr) && i < index; i++) {
        target = &((*target)->next);
      }

      SItem<T> *crnt = *target;
      if (crnt != nullptr) {
        *target = crnt->next;
      }
      return crnt;
    }
  }

public:
  SLList() : head(nullptr), tail(nullptr) {}
};
