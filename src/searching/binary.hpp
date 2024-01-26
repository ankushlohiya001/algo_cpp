#pragma once

template <class T> int sorted_position(T *arr, T what, int length);

/*
 * binary search based on binary tree,
 * so, to perform a binary_search, we need to have
 * a sorted array.
 * */
template <class T> int binary_search(T *arr, T what, int length) {
  // expecting sorted arr, to work correctly
  int position = sorted_position(arr, what, length);
  // we basically says, if possible position of `what` in arr,
  // actually contains it, means it's real ):
  // and in other case, possiblity is just possiblity :))
  if (position < length && arr[position] == what) {
    return position;
  } else {
    return -1;
  }
}

/*
 * as binary_search tells whether index if present
 * and -1 incase of not found,
 * but we can slightly modify this behaviour to so that,
 * instead of return -1 incase of not found, it returns
 * possible index, where it could've been present. :)
 * */
template <class T> int sorted_position(T *arr, T what, int length) {
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

  return start;
}
