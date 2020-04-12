/*
 Copyright [2020] <gcy>
 */

#ifndef SHARE_MEMORY_412_
#define SHARE_MEMORY_412

#define SHM_KEY_412 (7)

typedef struct _mem_struct_ {
  int flag;
  char str[100];
} MemStruct;

#ifdef __cplusplus
extern "C" {
#endif

int SetShareMemory(char *str);
int GetShareMemory(char *str);

#ifdef __cplusplus
}
#endif

#endif  // SHARE_MEMORY_412
