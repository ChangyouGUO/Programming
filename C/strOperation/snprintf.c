//　　建议使用snprintf进行字符串的拼接操作
//　　snprintf()完全覆盖第一个参数中的内容

#include <stdio.h>

#define FOLDER ("test")

int main(int argc, char **argv) {
  char path[10] = "/home/guo";
  char name[10] = "test";
  char kind[10] = "color";

  char savePath[100] = "What";

  snprintf(savePath, sizeof(savePath), "%s/%s/%s-%s%d.jpg", path, FOLDER, name,
           kind, 10);
  printf("%s\n", savePath);
  return 0;
}
