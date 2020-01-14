/*
 * 打开文件　fopen
 * 按行读取
 * .csv分割
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileName                                                               \
  ("/home/guo/moDisk/gCode/Programming/C/fileOperation/build/test.csv")

int main(int argc, char **argv) {
  char cFile[256] = fileName;
  char buffer[64];
  char *lineData;

  FILE *fp = NULL;
  if ((fp = fopen(cFile, "r")) != NULL) {
    fseek(fp, 0, SEEK_SET);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      lineData = strtok(buffer, ",");
      while (lineData != NULL) {
        printf("%d\n", atoi(lineData));
        lineData = strtok(NULL, ",");
      }
      printf("======\n");
    }
  }
  return 0;
}