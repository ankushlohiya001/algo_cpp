#pragma once

template <class T> void selection_sort(T *arr, long length) {
  for (long i = 0; i < length; i++) {
    long min_ind = i;
    for (long j = i + 1; j < length; j++) {
      if (arr[j] < arr[min_ind]) {
        min_ind = j;
      }
    }

    if (min_ind != i) {
      auto tmp = arr[min_ind];
      arr[min_ind] = arr[i];
      arr[i] = tmp;
    }
  }
}
