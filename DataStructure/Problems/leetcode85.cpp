/*
Copyright [2020] <gcy>
  Monotonic stack
  leetcode85.cpp
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stack>

#define LEN (1000)

// 复用leetcode84中的代码
int GetMaxArea(int n, int* heights) {
  std::stack<int> mono_stack;
  heights[n] = 0;
  int result = 0;
  int i = 0;
  for (; i <= n; i++) {
    while (!mono_stack.empty() && heights[mono_stack.top()] > heights[i]) {
      int value = heights[mono_stack.top()];
      mono_stack.pop();
      int left_index = mono_stack.empty() ? -1 : mono_stack.top();
      result = std::max(result, (i - left_index - 1) * value);
    }
    mono_stack.push(i);
  }
  return result;
}

// 将最大矩形面积求解，分解为按行叠加后，直方图最大面积(leetcode84)
int MaxRectangleArea(int r, int c, int (*array)[LEN]) {
  int sum_array[LEN];
  int result = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (0 == array[i][j]) {
        sum_array[j] = 0;
      } else {
        sum_array[j] += 1;
      }
    }
    result = std::max(result, GetMaxArea(c, sum_array));
  }
  return result;
}

int main() {
  int r = 0;
  int c = 0;
  scanf("%d", &r);
  scanf("%d", &c);
  int array[LEN][LEN];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", &array[i][j]);
    }
  }
  int result = MaxRectangleArea(r, c, array);
  printf("%d", result);
  return 0;
}