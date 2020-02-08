/*
P1525 关押罪犯

并查集
*/

#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

#define N (20005)
#define M (100005)
typedef struct war
{
    int x;
    int y;
    int val;
} war;

int group[N];
int enemy[N];
war record[M];

int cmp(war x, war y)
{
    return x.val > y.val;
}

int father(int x)
{
    stack<int> middleValue;
    while (group[x] != x)
    {
        middleValue.push(x);
        x = group[x];
    }
    while (!middleValue.empty())
    {
        group[middleValue.top()] = x;
        middleValue.pop();
    }
    return group[x];
}

int isSameSet(int x, int y)
{
    x = father(x);
    y = father(y);
    return x == y;
}

void combine(int x, int y)
{
    x = father(x);
    y = father(y);
    group[x] = y;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n + 1; i++)
    {
        group[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &(record[i].x), &(record[i].y), &(record[i].val));
    }

    sort(record, record + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (isSameSet(record[i].x, record[i].y))
        { //两个人已经在同一个牢房
            printf("%d", record[i].val);
            return 0;
        }

        if (!enemy[record[i].x])
        {
            enemy[record[i].x] = record[i].y;
        }
        else
        {
            combine(enemy[record[i].x], record[i].y);
        }

        if (!enemy[record[i].y])
        {
            enemy[record[i].y] = record[i].x;
        }
        else
        {
            combine(enemy[record[i].y], record[i].x);
        }
    }
    printf("%d", 0);
    return 0;
}