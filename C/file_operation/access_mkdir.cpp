// 　不可以递归创建文件夹, 只能一层一层判断，创建

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main() {
  string PathValue;
  string bnum = "123";
  PathValue = "/home/guo/moDisk/gCode/Programming/test";

  if (access(PathValue.c_str(), 0) == -1) {
    if (mkdir(PathValue.c_str(), S_IRWXU | S_IRWXG | S_IRWXO) != 0) {
      perror("mkdir %s PathValue");
    }
  }
}