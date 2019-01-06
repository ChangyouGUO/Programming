#include <stdio.h>

int main() {
    // char *name; 不分配内存，报错
    char name[81];
    scanf("%s", name);
    printf("%s", name);
    return 0;
}