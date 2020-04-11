/*
  Copyright [2020] <gcy>
  有一只乌龟，初始在0的位置向右跑。
  这只乌龟会依次接到一串指令，指令T表示向后转，指令F表示向前移动一个单位。乌龟不能忽视任何指令。
  现在我们要修改其中正好n个指令（一个指令可以被改多次，一次修改定义为把某一个T变成F或把某一个F变成T）。
  求这只乌龟在结束的时候离起点的最远距离。（假设乌龟最后的位置为x，我们想要abs(x)最大，输出最大的abs(x)）

  <https://ac.nowcoder.com/acm/problem/15294>

  这个题目采用dfs求解，直接暴力递归，4维度。
 */

#include <cmath>
#include <cstdio>
#include <cstring>

#define C (105)
#define N (55)
#define ABS(a) (a >= 0 ? a : -a)
#define ABS_MAX(a, b) (ABS(a) > ABS(b) ? ABS(a) : ABS(b))

static char plan[C];
static int n;
static int result = 0;
static int info[C][N][2 * C][2];
static int len = 0;

void turtleMove(int cur, int remain_steps, int reach, int forward) {
  if (cur >= len) {
    if (remain_steps % 2 == 0) {
      result = ABS_MAX(result, reach);
    }
    return;
  }

  // remain_steps == 0, 有些情况依旧可以前进
  if (remain_steps < 0) {
    return;
  }

  int fake_position = forward > 0 ? forward : 0;

  if (info[cur][remain_steps][reach][fake_position]) return;

  info[cur][remain_steps][reach][fake_position] = 1;

  if (plan[cur] == 'F') {
    turtleMove(cur + 1, remain_steps, forward + reach, forward);
    turtleMove(cur + 1, remain_steps - 1, reach, (-1) * forward);
  } else {
    turtleMove(cur + 1, remain_steps, reach, (-1) * forward);
    turtleMove(cur + 1, remain_steps - 1, forward + reach, forward);
  }
}

int main() {
  scanf("%s", plan);
  scanf("%d", &n);
  len = strlen(plan);

  turtleMove(0, n, 0, 1);
  printf("%d", result);
  return 0;
}