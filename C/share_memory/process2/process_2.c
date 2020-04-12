/*
 Copyright [2020] <gcy>
 */

#include <share_memory.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    char buf[100];
    char str[20] = "write by thread1";
    while (1) {
        SetShareMemory(str);
        printf("set: %s\n", str);
        usleep(500000);
    }
    return 0;
}