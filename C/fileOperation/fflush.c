#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  time_t的使用
  写入文件使用，需要创建上层文件夹
*/

int main(int argc, char **argv) {
  time_t t;
  struct tm *lt;
  time(&t);
  lt = localtime(&t);

  FILE *fp = NULL;
  char cFileName[128] =
      "/home/guo/moDisk/gCode/Programming/C/fileOperation/build/test.csv";

  fp = fopen(cFileName, "w+");
  for (int i = 0; i < 10; i++) {
    fprintf(fp, "%04d,%02d,%02d,%02d,%02d,%02d\n", lt->tm_year + 1900,
            lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    fflush(fp);
  }
  fclose(fp);
  return 0;
}