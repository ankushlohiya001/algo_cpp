#pragma once

template <class T> void swap(T &ref_a, T &ref_b) {
  T tmp = ref_a;
  ref_a = ref_b;
  ref_b = tmp;
}

template <class T> void divider_merger(T *arr, int from, int to);

/*
 * merge sort works by following way
 * 1. dividing the elements into half until less than 2 remains(in each pair).
 * 2. sort each pair,(approxx zero cost, since comparing 2 elements)
 * 3. then merge each pair, to form complete array again,:)
 *
 * (better works with recursion)
 *
 * TODOs:
 *  try to do some tail call optimizations.
 *  to reduce extra cost.
 * */
template <class T> void merge_sort(T *arr, int length) {
  divider_merger(arr, 0, length);
}

/*
 * this merging function is used to merge two sorted array,
 * to form new sorted array, it works in following manner. :D
 *
 * initialize two pointer for each array's front(first element),
 *
 * Note:
 *  Here' two array is emulated using subArray(array's sub part),
 *  specified by indexed ranges.
 * */
template <class T> void merge(T *arr, int from, int to) {
  int len = (to - from);
  int mid = from + len / 2;

  int i = from;

  while (i < mid) {
    if (arr[i] > arr[mid]) {
      swap(arr[i], arr[mid]);

      int j = mid;
      while (j + 1 < to && arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        j++;
      }
    }
    i++;
  }
}

template <class T> void divider_merger(T *arr, int from, int to) {
  int len = to - from;
  if (len < 2) {
    return;
  } else if (len == 2) {
    // sort two numbers,
    if (arr[from] > arr[to]) {
      swap(arr[from], arr[to]);
    }
  } else {

    // dividing and merging until they not reach count less than 3,
    int mid = from + len / 2;
    divider_merger(arr, from, mid); // first half

    divider_merger(arr, mid, len); // second half

    merge(arr, from, len);
  }
}
