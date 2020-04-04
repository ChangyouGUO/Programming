/*
  copyright [2020] <gcy>
  codeforce280B
  单调栈经典题目，寻找所有子序列中最大和第二大值的异或最大值
  假设当前值为第二大值，向前向后查找比此值大的第一个值，计算即可。
 */

#include <cstdio>
#include <iostream>
#include <stack>

#define N (100000 + 5)

static int nArray[N];

int ArrayXor(int num) {
  std::stack<int> mono_stack;
  int result = 0;
  for (int i = 0; i < num; i++) {
    while (!mono_stack.empty() && nArray[mono_stack.top()] < nArray[i]) {
      mono_stack.pop();
    }

    if (!mono_stack.empty()) {
      result = std::max(result, nArray[mono_stack.top()] ^ nArray[i]);
    }

    mono_stack.push(i);
  }
  return result;
}

void Reverse(int num) {
  if (num <= 1) {
    return;
  }
  for (int i = 0; i < num / 2; i++) {
    int tmp = nArray[i];
    nArray[i] = nArray[num - i - 1];
    nArray[num - i - 1] = tmp;
  }
}

int main() {
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &nArray[i]);
  }
  int result = ArrayXor(num);
  Reverse(num);
  result = std::max(result, ArrayXor(num));
  printf("%d", result);
  return 0;
}