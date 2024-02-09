#pragma once
#include <stdexcept>

/* Linked List Data Structure,
 * it contains elements, which have reference to other element,
 * and so on.
 *
 * linked list is fast for end based insertion,removal.
 * it's havin' following variants:
 *  Singly,
 *  Doubly,
 *  Circular
 * */
template <class T> struct Item {
  T data;

  // accessing data from `get_data`, as user might add,
  // their own Item type, and storage destination may vary.
  virtual T get_data() { return data; }
};

template <class T, class IT = Item<T>> class LinkedList {
protected:
  long count; // no of elements/items in linked list

  // to access element at arbitrary position,
  virtual IT *item_at(int index) = 0;

  // to insert element at arbitrary position,
  // need to implemented by inherited class.
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
    // front element is the first element.
    IT *item = item_at(0);
    return item->get_data();
  }

  void insert_front(T data) {
    // since LinkedList is end user Structure, end user
    // dont' care about item type, they just have their data,
    //
    // so, implementer create own `insert_item_at` function,
    // where we pass `item` type which we created below. :)
    IT *item = new IT(data);
    insert_item_at(0, item); // implementer's insertion
    count++;
  }

  T remove_front() {
    if (is_empty()) {
      // panicing incase of empty removal
      throw std::underflow_error("empty stack");
    } else {
      IT *old_front = remove_item_from(0);
      // modifying count here only, because it's just linked
      // list's thing :)
      count--;

      T data = old_front->get_data();
      // freeing memory,
      // as LinkedList is which alotted memory. :)
      delete old_front;
      return data;
    }
  }

  T back() {
    // back refers to last element.
    IT *item = item_at(size() - 1);
    return item->get_data();
  }

  void insert_back(T data) {
    IT *item = new IT(data);
    // inserting back means, placing new item at
    // index greater than last element's index (len-1)
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

/* ------------------------------------------------
 * singly linked list
 * here's item contains:
 *  data,
 *  reference to next element only,
 *
 * better( O(1) ) for following:
 *  insert_front,
 *  insert_back,
 *  remove_front
 * */

template <class T> struct SItem {
  T data;
  SItem *next;
  SItem(T dat) : data(dat), next(nullptr) {}
  T get_data() { return data; }
};

template <class T> class SLList : public LinkedList<T, SItem<T>> {
public:
  SItem<T> *head;

  // havin' tail reference makes insertion at back fast, ie. O(1)
  // else we would need to travel upto tail item.
  SItem<T> *tail;

  // TODOs
  // [] make last element accessing faster,
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
      // case where LinkedList is completely empty.
      // so,
      head = tail = item;
    } else if (index >= this->size()) {
      // TODOs
      // need to reconsider :)
      //  appending to last in case of element is larger than
      //  length of list.
      tail->next = item;
      tail = item;
    } else {
      // traversing to targetted index,
      SItem<T> **target = &head;
      for (int i = 0; (*target != nullptr) && i < index; i++) {
        target = &((*target)->next);
      }

      if (*target != nullptr) {
        // case when it need to insert at non last index.
        item->next = *target;
      }
      *target = item;
    }
  }

  SItem<T> *remove_item_from(int index) {
    if (head == nullptr) {
      // ignoring removing from empty
      return nullptr;
    } else if (index == 0) {
      // incase of head removal
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

/*---------------------------------------
 * doubly linked list
 *  here's item contains:
 *  data,
 *  reference to next and previous element,
 *
 * better( O(1) ) for end based insertion, removal.
 * */
template <class T> struct DItem {
  T data;
  DItem *prev;
  DItem *next;
  DItem(T dat) : data(dat), prev(nullptr), next(nullptr) {}
  T get_data() { return data; }
};

template <class T> class DLList : public LinkedList<T, DItem<T>> {
public:
  DItem<T> *head;
  DItem<T> *tail;

  DItem<T> *item_at(int index) {
    int len = this->size();
    DItem<T> *ref = head;
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

  void insert_item_at(int index, DItem<T> *item) {
    if (head == nullptr) {
      head = tail = item;
    } else if (index >= this->size()) {
      tail->next = item;
      item->prev = tail;
      tail = item;
    } else {
      DItem<T> **target = &head;
      for (int i = 0; (*target != nullptr) && i < index; i++) {
        target = &((*target)->next);
      }
      if (*target != nullptr) {
        item->next = *target;
        item->prev = (*target)->prev;
        (*target)->prev = item;
      }
      *target = item;
    }
  }

  DItem<T> *remove_item_from(int index) {
    if (head == nullptr) {
      return nullptr;
    } else if (index == 0) {
      DItem<T> *old = head;
      head = old->next;
      return old;
    } else {
      DItem<T> **target = &head;
      for (int i = 0; (*target != nullptr) && i < index; i++) {
        target = &((*target)->next);
      }

      DItem<T> *crnt = *target;
      if (crnt != nullptr) {
        *target = crnt->next;
      }
      return crnt;
    }
  }

public:
  DLList() : head(nullptr), tail(nullptr) {}
};
