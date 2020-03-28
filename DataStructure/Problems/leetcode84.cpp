/*
  Copyright [2020] <GCY>
  Monotonic stack
  计算面积需要两侧边界和高度。
  考虑只要右侧的数值比左侧开头的值小，此时统计的区域就已经形成。
  采用单调递减栈(增减性为出栈顺序)
  leetcode 84
 */

#include <stdio.h>

#include <iostream>
#include <stack>

// leetcode doesn't give number limit
#define LEN (100)

// 注意：有效区间不是i - left_index, 应该是i- left_left_index-1
// 考虑到最后一个值的边界情况，stack 最开始压入一个0
/*
int GetMaxArea(int n, int* heights) {
  std::stack<int> mono_stack;
  mono_stack.push(-1);
  int result = 0;
  int i = 0;
  for (; i < n; i++) {
    while (mono_stack.size() > 1 && heights[mono_stack.top()] > heights[i]) {
      int value = heights[mono_stack.top()];
      mono_stack.pop();
      result = std::max(result, (i - mono_stack.top() - 1) * value);
    }
    mono_stack.push(i);
  }
  while (mono_stack.size() > 1) {
    int value = heights[mono_stack.top()];
    mono_stack.pop();
    result = std::max(result, (i - mono_stack.top() - 1) * value);
  }
  return result;
}
*/

// 给定数为非负整数，在height中多压如一个0，可以将最后stack剩余变量的情况和遍历时while的情况结合在一起。
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

int main() {
  int n;
  int heights[LEN];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &heights[i]);
  }

  int result = GetMaxArea(n, heights);
  printf("%d\n", result);

  return 0;
}