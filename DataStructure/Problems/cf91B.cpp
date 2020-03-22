//  Copyright [2020] <GCY190811>
/*
  codeforces 91B
  二分搜索 + 后缀数组最小值
 */

#include <cstdio>
#include <cstdlib>

#define N (100000)

int FindMinRightWalruses(int *happiness, int *subfix_min, int v, int l, int r) {
  if (l == r) {
    return l;
  } else if (l + 1 == r) {
    return happiness[r] < v ? r : l;
  }

  int middle = l + ((r - l) >> 1);
  if (v > subfix_min[middle]) {
    return FindMinRightWalruses(happiness, subfix_min, v, middle + 1, r);
  } else {
    return FindMinRightWalruses(happiness, subfix_min, v, l, middle);
  }
}

void WalrusesPleasure(int n, int *walruses, int *result) {
  int subfix_min[N];
  subfix_min[n - 2] = walruses[n - 1];
  for (int i = n - 3; i >= 0; i--) {
    subfix_min[i] = walruses[i + 1] < subfix_min[i + 1] ? walruses[i + 1]
                                                        : subfix_min[i + 1];
  }

  for (int i = 0; i < n - 1; i++) {
    if (walruses[i] <= subfix_min[i]) {
      result[i] = -1;
    } else {
      int right_index =
          FindMinRightWalruses(walruses, subfix_min, walruses[i], i + 1, n - 1);
      result[i] = right_index - i - 1;
    }
  }

  result[n - 1] = -1;
  return;
}

int main() {
  int n = 0;
  int walruses[N];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &walruses[i]);
  }
  int result[N];
  WalrusesPleasure(n, walruses, result);

  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }
}
