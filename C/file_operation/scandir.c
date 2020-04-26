/*
    CopyRight [2020] <gcy>
 */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPDATE_MD5_PATH \
  ("/home/guo/moSource/mpkg/tmp/rootfs/home/root/Controls")
#define UPDATE_MD5_NAME ("UPDATE_MD5")

static char update_md5[256];

int getMatchFileContent() {
  struct dirent **namelist;
  int n;
  int i;
  n = scandir(UPDATE_MD5_PATH, &namelist, 0, alphasort);
  if (n < 0) {
    return -2;
  } else {
    for (i = 0; i < n; i++) {
      if (0 == strcmp(namelist[i]->d_name, UPDATE_MD5_NAME)) {
        char file_path[256];
        char file_name[11];
        snprintf(file_path, sizeof(file_path), "%s/%s", UPDATE_MD5_PATH,
                 UPDATE_MD5_NAME);
        FILE *fp = NULL;
        if ((fp = fopen(file_path, "r")) != NULL) {
          fseek(fp, 0, SEEK_SET);
          fgets(file_name, sizeof(file_name), fp);
        }
        snprintf(update_md5, sizeof(update_md5), "%s", file_name);
        return 0;
      }

      free(namelist[i]);
    }
    free((namelist));
  }
  return -1;
}

int main(int argc, char **argv) {
  if (0 == getMatchFileContent()) {
    printf("%s\n", update_md5);
  }
  return 0;
}