/*
快速幂算法, 假设取后几位数据
(a+b)%c = ((a%c) + (b%c))%c
(a*b)%c = ((a%c)*(b%c))%c
(a-b)%c = ((a%c) - (b%c))%c
*/
#include "stdlib.h"
#include "stdio.h"

void fast_power(long base, long power, int c)
{
    if (0 == base)
    {
        printf("invalid!\n");
        return;
    }
    else if (0 == power)
    {
        printf("1");
        return;
    }

    char bNegative = 0;
    // 注意这里进行取反
    if (power < 0)
    {
        bNegative = 1;
        power *= -1;
    }
    int result = 1.0;
    while (power > 0)
    {
        if (power & 1) //  相当于判断奇偶数
        {
            result = result * base % c;
        }
        power >>= 1; //  包含奇数-1，再/2
        base = (base * base) % c;
    }

    printf("%f", bNegative == 1 ? 1.0 / result : result);
}

int main()
{
    long base;
    long power;
    int c;
    scanf("%ld", &base);
    scanf("%ld", &power);
    scanf("%d", &c);
    fast_power(base, power, c);
    return 0;
}