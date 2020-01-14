#include <stdio.h>
#include <stdlib.h>

/*写入文件 echo
*/

int main(int argc, char **argv) {
  char file[256];
  int fileNum = 123;
  if (snprintf(file, sizeof(file), "writefile_%4d.csv", fileNum) < 0) {
    perror("snprintf");
  }

  char cmd[256];
  float writeValue = 123.456f;
  snprintf(cmd, sizeof(cmd), "echo %.2f >> %s", writeValue, file);
  system(cmd);
}
