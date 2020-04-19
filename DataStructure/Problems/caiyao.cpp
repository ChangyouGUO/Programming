/*
  Copyright [gcy] <2020>
  0-1背包问题：
  从ｎ件物品中进行选取，每件物品只能拿一次，权衡物品的价值和重量，放在背包中，
  背包有重量限制。
  求解最优答案
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a > b) ? a : b)

int time[105];
int value[105];
// i 前ｉ棵，ｊ时间，dp为最大价值
int dp[105][1005];
int dpOne[1005];

// two dimension dp
int getMaxValueDp1(int T, int M) {
  // 采集ｉ棵
  for (int i = 1; i <= M; i++) {
    // 具有的时间
    for (int j = 1; j <= T; j++) {
      if (j < time[i]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = MAX(dp[i - 1][j], (dp[i - 1][j - time[i]] + value[i]));
      }
    }
  }
  return dp[M][T];
}

// one dimension dp
int getMaxValueDp2(int T, int M) {
  for (int i = 1; i <= M; i++) {
    for (int j = T; j > 0; j--) {
      if (j >= time[i]) {
        dpOne[j] = MAX(dpOne[j], dpOne[j - time[i]] + value[i]);
      }
    }
  }
  return dpOne[T];
}

int main() {
  int T;
  int M;
  scanf("%d", &T);
  scanf("%d", &M);

  for (int i = 1; i <= M; i++) {
    scanf("%d", &time[i]);
    scanf("%d", &value[i]);
  }

  // int ret1 = getMaxValueDp1(T, M);
  int ret2 = getMaxValueDp2(T, M);
  // printf("%d\n", ret1);
  printf("%d\n", ret2);

  return 0;
}