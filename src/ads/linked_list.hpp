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

  bool is_empty() { return head == nullptr; }

  void insert_front(T data) {
    Item<T> *new_head = {data, head};
    head = new_head;
    if (tail == nullptr) {
      tail = head;
    }
    count++;
  }

  T remove_front() {
    if (is_empty()) {
      throw std::underflow_error("empty stack");
    } else {
      Item<T> *old_head = head;
      head = head->next;
      return old_head->data;
    }
  }

  void insert_back(T data) {
    if (is_empty()) {
      insert_front(data);
    } else {
      Item<T> *new_tail = {data, nullptr};
      tail->next = new_tail;
      tail = new_tail;
    }
  }

  T remove_back() {
    if (is_empty()) {
      throw std::underflow_error("empty stack");
    } else {
      // todo iteration need to reach item
      // previous to tail.
    }
  }
};
