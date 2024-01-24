#pragma once

template <class T> int linear_search(T *arr, T what, int length) {
  for (int i = 0; i < length; i++) {
    if (arr[i] == what) {
      return i;
    }
  }
  return -1; // indicates not found!!
}

template <class T> bool check_contains(T *arr, T what, int length) {
  return linear_search(arr, what, length) != -1; // ;))
}
