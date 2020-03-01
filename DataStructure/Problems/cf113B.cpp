/*
    cf113B Petr #Long ago,
    when Petya was a schoolboy,
    he was very much interested in the Petr #language grammar.
    During one lesson Petya got interested in the following question : 
    how many different continuous substrings starting with
    the sbegin s_{begin} sbegin​ and ending with the send s_{end} 
    send​(it is possible sbegin = send s_{begin} = s_{end} sbegin​ = send​),
    the given string t t t has.Substrings are different if and only
    if their contents aren 't equal, their positions of occurence don' t matter.
    Petya wasn 't quite good at math, that' s why he couldn't count this number. Help him !*/

#include "stdio.h"
#include "string.h"
#define LEN (2001)

void getNextArray(char *str, char *nextArray)
{
    int len = strlen(str);
    nextArray[0] = -1;
    nextArray[1] = 0;

    int strIndx = 0;
    int nextIndex = 2;
    while (nextIndex <= len)
    {
        if (str[strIndx] == str[nextIndex - 1])
        {
            nextArray[nextIndex] = strIndx + 1;
            nextIndex++;
            strIndx++;
        }
        else if (strIndx == 0)
        {
            nextArray[nextIndex++] = 0;
        }
        else
        {
            strIndx = nextArray[strIndx];
        }
    }
}

void KMP(char *pStr, char *pSubstr, int *pIndex, int *indexNum)
{
    char nextArray[LEN];
    getNextArray(pSubstr, nextArray);
    int lenstr = strlen(pStr);
    int lensub = strlen(pSubstr);

    int strIndex = 0;
    int subIndex = 0;
    while (strIndex < lenstr)
    {
        if (pStr[strIndex] == pSubstr[subIndex])
        {
            strIndex++;
            subIndex++;
            if (subIndex == lensub)
            {
                pIndex[(*indexNum)++] = strIndex - lensub;
                subIndex = 0;
                strIndex = strIndex - lensub + 1;
            }
        }
        else if (subIndex == 0)
        {
            strIndex++;
        }
        else
        {
            subIndex = nextArray[subIndex];
        }
    }
}

int main()
{
    char strt[LEN];
    char strStart[LEN];
    char strEnd[LEN];

    scanf("%s", strt);
    scanf("%s", strStart);
    scanf("%s", strEnd);

    int startIndexs[LEN];
    int endIndexs[LEN];
    int startNum = 0;
    int endNum = 0;
    KMP(strt, strStart, startIndexs, &startNum);
    KMP(strt, strEnd, endIndexs, &endNum);

    // debug
    // printf("%s\t%s\t%s", strt, strStart, strEnd);
    // printf("\nstart\n");
    // for (int i = 0; i < startNum; i++)
    // {
    //     printf("%d ", startIndexs[i]);
    // }
    // printf("\nend\n");
    // for (int i = 0; i < endNum; i++)
    // {
    //     printf("%d ", endIndexs[i]);
    // }
    // printf("\n");

    // force compare

    int total = 0;
    char allArray[LEN][LEN];
    for (int l = 0; l < startNum; l++)
    {
        for (int r = 0; r < endNum; r++)
        {
            int begin = startIndexs[l];
            int end = endIndexs[r] + strlen(strEnd);
            if (begin > end)
            {
                continue;
            }
            // printf("%d, %d", begin, end);
            char result[end - begin + 1];
            strncpy(result, &strt[begin], end - begin);
            result[end - begin] = '\0';
            // printf("%s\n", result);

            int i = 0;
            while (i < total && 0 == strcmp(result, allArray[i]))
            {
                i++;
            }
            if (i == total)
            {
                strcpy(allArray[total++], result);
            }
        }
    }
    printf("%d", total);
    return 0;
}