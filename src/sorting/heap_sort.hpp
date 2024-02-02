#pragma once

template <class T> void swap(T &ref_a, T &ref_b) {
  T tmp = ref_a;
  ref_a = ref_b;
  ref_b = tmp;
}

template <class T> void move_down(T *arr, int index, int end) {
  int crnt_idx = index;
  while (true) {
    int a_idx = crnt_idx * 2 + 1; // left child index
    if (a_idx >= end)
      break;
    int b_idx = crnt_idx * 2 + 2; // right child index

    if (b_idx >= end) {
      b_idx = a_idx;
    }
    int rare = crnt_idx;

    if (arr[a_idx] > arr[rare]) {
      rare = a_idx;
    }

    if (arr[b_idx] > arr[rare]) {
      rare = b_idx;
    }

    if (rare == crnt_idx) {
      break;
    } else {
      swap(arr[rare], arr[crnt_idx]);
      crnt_idx = rare;
    }
  }
}
/*
 * heap sort works by first making array into binary heap,
 * binary heap conversion works by following way,
 */

template <class T> void heap_sort(T *arr, int length) {
  int last_leaf_idx = (length + (length & 1)) / 2;
  int crnt = last_leaf_idx;
  /*
   * we move_down nodes one by one, we start from last(leaving leaf node).
   * this is important because there's always half count of leaf nodes.
   * */
  while (crnt >= 0) {
    move_down(arr, crnt--, length);
  }

  /*
   * we then swap first node to last node, and move down first node
   * to ending leaving last node,
   * length decreases in each iteration.
   * */
  for (int i = length - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    move_down(arr, 0, i);
  }
}
