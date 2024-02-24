#pragma once

void div_mod(int de, int no, int *div, int *mod) {
  *div = de / no;
  *mod = de - (*div) * no;
}

int hcf(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return hcf(b, a % b);
  }
}

inline int gcd(int a, int b) { return hcf(a, b); }

int lcm(int a, int b) { return (a / hcf(a, b)) * b; }

double sum(double *arr, int len) {
  double sum = 0;
  for (int i = 0; i < len; i++) {
    sum += arr[i];
  }
  return sum;
}

double average(double *arr, int len) { return sum(arr, len) / len; }
