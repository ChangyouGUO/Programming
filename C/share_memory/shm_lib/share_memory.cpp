/*
 Copyright [2020] <gcy>
 */

#include "share_memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sys/shm.h"

static void *pShm = NULL;
static MemStruct *pMemStruct = NULL;
static int shm_id = 0;

void InitShareMemory() __attribute__((constructor(101)));
void DestoryShareMemory() __attribute__((destructor(201)));

void InitShareMemory() {
  shm_id = shmget((key_t)SHM_KEY_412, sizeof(MemStruct), 0666 | IPC_CREAT);
  if (shm_id == -1) {
    fprintf(stderr, "shmget failed\n");
    exit(EXIT_FAILURE);
  }

  pShm = shmat(shm_id, 0, 0);
  if (pShm == (void *)-1) {
    fprintf(stderr, "shmat failed\n");
    exit(EXIT_FAILURE);
  }
  pMemStruct = (MemStruct *)pShm;
  return;
}

void DestoryShareMemory() {
  if (shmdt(pShm) == -1) {
    fprintf(stderr, "shmdt failed\n");
    exit(EXIT_FAILURE);
  }

  shmctl(shm_id, IPC_RMID, 0);
  return;
}

int SetShareMemory(char *str) {
  strncpy(pMemStruct->str, str, strlen(str) + 1);
  pMemStruct->flag = 1;
  return 0;
}

int GetShareMemory(char *str) {
  if (0 == pMemStruct->flag) {
    return -1;
  }

  strncpy(str, pMemStruct->str, strlen(pMemStruct->str) + 1);
  pMemStruct->flag = 0;
  return 0;
}