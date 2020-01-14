#include <stdio.h>
#define SIZE 4

void sum(int *ar, int n);

void sum1(int ar[], int n);   //两者都可以，int ar[] 只能作为定义形式参数

void sum2(const int ar[], int n); //函数原型和函数定义中，加入const,告诉编译器，说明函数意图不是修改数组中的数据内容．// 这里的const不是要求，ar是const定义的数组

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