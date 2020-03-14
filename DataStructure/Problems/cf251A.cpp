/*
    cf251A
    "Little Petya likes points a lot. Recently his mom has presented him n points lying on the line OX . Now Petya is wondering in how many ways he can choose three distinct points so that the distance between the two farthest of them doesn't exceed d .
    Note that the order of the points inside the group of three chosen points doesn't matter.
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN (100000)

void findNumbers(int n, long long int d, long long int *points, long long int *resultNum)
{
    int left = 0;
    int right = 0;
    int size = 1;
    while (right <= n)
    {
        if ((right + 1 >= n && points[right] - points[left] <= d) || points[right] - points[left] > d)
        {
            printf("here\n");
            if (points[right] - points[left] > d)
            {
                *resultNum += (size - 1) * (size - 2) * (size - 3) / 6;
            }
            else
            {
                *resultNum += (size) * (size - 1) * (size - 2) / 6;
            }
            while (points[right] - points[left] > d)
            {
                left++;
                size--;
            }
        }
        right++;
        size++;
    }
}

int main()
{
    int n;
    long long d;
    long long points[LEN];
    scanf("%d", &n);
    scanf("%lld", &d);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &points[i]);
    }

    long long resultNum = 0;
    findNumbers(n, d, points, &resultNum);
    printf("%lld", resultNum);
}