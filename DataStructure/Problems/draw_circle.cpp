/*
 CopyRight [2020] <gcy>
 */
#include <cmath>
#include <cstdio>

#define SIZE (6561)
#define LEN (9)
static int maskArray[SIZE][SIZE];

void drawCircle(int level, int x, int y) {
  if (level == 0) {
    maskArray[y][x] = 1;
  } else {
    int offset = pow(3, level - 1);
    drawCircle(level - 1, x, y);
    drawCircle(level - 1, x - offset, y + offset);
    drawCircle(level - 1, x + offset, y + offset);
    drawCircle(level - 1, x, y + 2 * offset);
  }
}

void printCircle(int level) {
  int offset = pow(3, level);
  for (int row = 0; row < offset; row++) {
    int col = offset;
    while (0 == maskArray[row][col]) {
      col--;
    }
    for (int i = 0; i <= col; i++) {
      if (1 == maskArray[row][i]) {
        printf("O");
        maskArray[row][i] = 0;
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  int n = 0;
  int num[LEN];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }

  for (int i = 0; i < n; i++) {
    drawCircle(num[i], (int)pow(3.0, num[i]) >> 1, 0);
    printCircle(num[i]);
  }

  return 0;
}
