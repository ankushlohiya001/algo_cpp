#pragma once

#include <stdexcept>
template <class T> struct Item {
  T data;     // data it contains
  Item *next; // reference to next item
};

template <class T> class SLList {
  // single linked list, having ref to next
  // element only
  Item<T> *head; // starting point
  Item<T> *tail; // ending point,
                 // to avoid insertion at last overhead
  long count;

public:
  SLList() : head(nullptr), tail(nullptr), count(0) {}

  long size() { return count; }

  bool is_empty() {
    // helpfull for checking list before removing :))
    return head == nullptr;
  }

  void insert_front(T data) {
    // it's as simple as following
    // create a new item(with given data)
    // to make it head, we can just set current head
    // as new item's next item,
    // ie. newItem -> head -> rest list...
    Item<T> *new_head = new Item<T>{data, head}; // for this one
    head = new_head;
    if (tail == nullptr) {
      // since list was empty, head and tail will be same ;)
      tail = head;
    }
    count++;
  }

  // remember to free memory for heap allocated Items ;)
  T remove_front() {
    if (is_empty()) {
      // avoiding an obvious issue ;))
      throw std::underflow_error("empty stack");
    } else {
      // else setting head's next item as new head
      // and return old_head's data.
      Item<T> *old_head = head;
      head = head->next;
      return old_head->data;
    }
  }

  void insert_back(T data) {
    if (is_empty()) {
      // in case of empty list, is similar to that of
      // insert_front :)
      insert_front(data);
    } else {
      // also set newItem as next to tail,
      // and making newItem as tail, that simple ;)
      Item<T> *new_tail = new Item<T>{data, nullptr}; // also for this
      tail->next = new_tail;
      tail = new_tail;
    }
  }

  // remember to free memory for heap allocated Items ;)
  T remove_back() {
    // complicated one, avoid reading ;()
    // just kidding ;)
    if (is_empty()) {
      // old obvious one issue
      throw std::underflow_error("empty stack");
    } else if (head == tail) {
      // since there's only one element, there's no
      // element previous to tail, obvious ;)
      Item<T> *old_tail = tail;
      head = tail = nullptr;
      return old_tail->data;
    } else {
      // since its' single linked list, we dont've previous
      // item reference, so iteration is needed to reach item
      // previous to tail.
      Item<T> *root = head;
      while (root && root->next && root->next->next != nullptr) {
        root = root->next;
      }
      Item<T> *old_tail = tail;
      root->next = nullptr;
      tail = root;
      return old_tail->data;
    }
  }
};
