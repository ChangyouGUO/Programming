/*
#include <pthread.h>
int
pthread_create(       pthread_t*        thread,
               const  pthread_attr_t*   attr,
                      void*             (*start_routine) (void*),
                      void*             arg);
*/

#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

typedef struct myarg_t {
  int a;
  int b;
} myarg_t;

typedef struct myret_t {
  int x;
  int y;
} myret_t;

void *mythread(void *arg) {
  myarg_t *m = (myarg_t *)arg;
  printf("%d %d\n", m->a, m->b);
  myret_t *r = (myret_t *)malloc(sizeof(myret_t));
  r->x = 1;
  r->y = 2;
  return (void *)r;
}

int main(int argc, char **argv) {
  pthread_t p;
  int rc;
  myret_t *m;

  myarg_t args;
  args.a = 10;
  args.b = 20;
  rc = pthread_create(&p, NULL, mythread, &args);
  if (rc < 0) {
    perror("pthread_create");
  }
  pthread_join(p, (void **)&m);
  printf("returned %d %d\n", m->x, m->y);
  return 0;
}