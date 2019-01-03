#include <stdio.h>
#define SIZE 4

void sum(int *ar, int n);

void sum1(int ar[], int n);   //两者都可以，int ar[] 只能作为定义形式参数

int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;

    pti = dates;
    ptf = bills;
    printf("%23s %15s\n", "short", "double");

    for ( index = 0; index < SIZE; index++)
    {
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    }
    return 0;
}