//　 遍历文件夹

#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
  struct dirent **namelist;
  int n;
  int i;
  string path = "/home/guo/Desktop/test/";
  n = scandir(path.c_str(), &namelist, 0, alphasort);
  if (n < 0) {
    perror("scandir");
  } else {
    printf("%d\n", n);
    for (i = 0; i < n; i++) {
      printf("%s\n", namelist[i]->d_name);
      if (i > 1) {
        char filePath[256];
        if (path[path.size() - 1] == '/') {
          snprintf(filePath, sizeof(filePath), "%s%s", path.c_str(),
                   namelist[i]->d_name);
        } else {
          snprintf(filePath, sizeof(filePath), "%s/%s", path.c_str(),
                   namelist[i]->d_name);
        }

        printf("%s\n", filePath);
        // remove(filePath);
      }
      free(namelist[i]);
    }
    free((namelist));
  }

  return 0;
}