/*
    cf251A
    "Little Petya likes points a lot. Recently his mom has presented him n
   points lying on the line OX . Now Petya is wondering in how many ways he can
   choose three distinct points so that the distance between the two farthest of
   them doesn't exceed d .
    Note that the order of the points inside the group of three chosen points
   doesn't matter.

   1. 单调队列求解。
   每次到边界时，不采用C n 3的方法，使用C n-1 2
   2的方法，将组合的所有可能清晰的分割到最后一个值的变更。

   2. 二分法
   使用lower_bound。<https://blog.csdn.net/qq_40160605/article/details/80150252>
   在有序数组中插入一个值，返回插入此值不影响数组顺序的第一个值。
   及返回的是第一个大于或等于此值的位置。
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

#define LEN (100000)

void FindNumbersQueue(int n, long long int d, long long int *points,
                      long long int *resultNum) {
  queue<long long int> q;
  for (int i = 0; i < n; i++) {
    q.push(points[i]);
    while (q.back() - d > q.front()) q.pop();
    int len = q.size() - 1;
    *resultNum += (long long int)len * (len - 1) / 2;
  }
}

void FindNumbersBinarySearch(int n, long long int d, long long int *points,
                             long long int *resultNum) {
  // lower_bound 从数组 begin到end-1位置 二分查找
  int j = 0;
  for (int i = 1; i < n; i++) {
    j = i - (lower_bound(points, points + i, points[i] - d) - points);
    *resultNum += (long long int)j * (j - 1) / 2;
  }
}

int main() {
  int n;
  long long d;
  long long points[LEN];
  scanf("%d", &n);
  scanf("%lld", &d);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &points[i]);
  }

  long long resultNum = 0;
  FindNumbersBinarySearch(n, d, points, &resultNum);
  printf("%lld", resultNum);
}