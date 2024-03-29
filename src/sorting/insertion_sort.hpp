#pragma once
#include "binary.hpp"
#include <utility>

/*
 * insertion sort works in following manner:
 * interate over list
 * for each iteration,
 * move current element to the left,
 * until it reaches to a state where left element
 * is already less/great to current element
 *
 * the efficiency of insertion_sort can be improved
 * with binary search insertion.
 * */

template <class T> void insertion_sort(T *arr, long length) {
  for (long i = 1; i < length; i++) {
    long crnt = i;
    while (crnt > 0 && arr[crnt - 1] > arr[crnt]) {
      std::swap(arr[crnt], arr[crnt - 1]);
      crnt--;
    }
  }
}

template <class T> void binary_insertion_sort(T *arr, long length) {
  for (long i = 1; i < length; i++) {
    T crnt = arr[i];
    int pos = sorted_position(arr, crnt, i);
    if (pos == i) {
      continue;
    }
    for (long j = i; j > pos; j--) {
      arr[j] = arr[j - 1];
    }
    arr[pos] = crnt;
  }
}
