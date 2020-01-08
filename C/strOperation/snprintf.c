// 建议使用snprintf进行字符串的拼接操作

#include <stdio.h>

int main(int argc, char **argv) {
  char path[10] = "/home/guo";
  char name[10] = "test";
  char kind[10] = "color";

  char savePath[100] = {0};

  snprintf(savePath, sizeof(savePath), "%s/%s-%s%d.jpg", path, name, kind, 10);
  printf("%s\n", savePath);
  return 0;
}
