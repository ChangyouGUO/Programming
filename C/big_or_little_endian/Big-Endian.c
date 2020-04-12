// 大小端判断

#include <stdio.h>

int checkCPU() {
  union w {
    int a;
    char b;
  } c;

  c.a = 1;

  return (c.b == 1);
}
int main(int argc, char *argv[]) {
  checkCPU() ? printf("little-endian\n") : printf("Big-endian\n");
  return 0;
}