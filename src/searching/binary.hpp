#pragma once

/*
 * binary search based on binary tree,
 * so, to perform a binary_search, we need to have
 * a sorted array.
 * */
template <class T> int binary_search(T *arr, T what, int length) {
  // expecting sorted arr, to work correctly
  int start = 0;
  int end = length;
  while (start < end) {
    int middle = start + (end - start) / 2;
    if (what < arr[middle]) {
      end = middle;
    } else if (what > arr[middle]) {
      start = middle + 1;
    } else {
      return middle;
    }
  }

  return -1;
}
