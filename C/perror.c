#include <stdio.h>
#include <stdlib.h>
// perror 并不会使程序崩溃

int main() {
  for (int i = 0; i < 5; i++) {
    printf("%d ", i);
  }
  printf("\n");
  FILE* fp;
  fp = fopen("./txt", "r");
  if (fp == NULL) {
    perror("id not useful");
  }
  int count = 10;
  while (count--) {
    for (int i = 0; i < 5; i++) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}