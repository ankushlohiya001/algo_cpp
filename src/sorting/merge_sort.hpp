#pragma once

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
template <class T> void merge_sort(T *arr, int length) {}
