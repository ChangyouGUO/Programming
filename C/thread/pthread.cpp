#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

enum threadCase { Pointer, ErrorPointer };

typedef struct my_struct {
  int a;
  int b;
} my_struct;

void *threadFunc(void *args) {
  my_struct *arg = (my_struct *)args;
  arg->a++;
  return (void *)arg;
}

void pointerFunc() {
  pthread_t thread1;
  my_struct args;
  args.a = 0;
  args.b = 0;
  int ret = 0;

  if ((ret = pthread_create(&thread1, NULL, threadFunc, (void *)&args)) != 0) {
    perror("pthread_create");
  }

  my_struct *retValue;
  if ((ret = pthread_join(thread1, (void **)&retValue)) != 0) {
    perror("pthread_join");
  };

  assert(retValue->a == 1);
  printf("%d\n", retValue->a);
}

int main(int argc, char **argv) {
  enum threadCase case = ErrorPointer;
  switch (case) {
  case Pointer: {
    pointerFunc();
    break;
  }
  case ErrorPointer: {
  }

  default:
    perror(" case id none cmd");
    break;
  }

  return 0;
}