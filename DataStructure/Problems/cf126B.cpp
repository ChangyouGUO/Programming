/* codeforces 126B
*/
/*
Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them.

A little later they found a string s , carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s .

Prefix supposed that the substring t is the beginning of the string s ; Suffix supposed that the substring t should be the end of the string s ; and Obelix supposed that t should be located somewhere inside the string s , that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s . Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.
*/

#include "stdio.h"
#include "string.h"
#define LEN (1000000)

int main()
{
    char input[LEN];
    scanf("%s", input);

    int len = strlen(input);
    int strfix[LEN];
    strfix[0] = -1;
    strfix[1] = 0;

    int preIndex = 0;
    int index = 2;
    int maxlen = 0;

    //next 数组
    while (index <= len)
    {
        printf("here");
        if (input[preIndex] == input[index - 1])
        {
            strfix[index] = preIndex + 1;
            if (index != len)
            {
                maxlen = maxlen > strfix[index] ? maxlen : strfix[index];
            }
            index++;
            preIndex++;
        }
        else if (preIndex == 0)
        {
            strfix[index++] = 0;
        }
        else
        {
            preIndex = strfix[preIndex];
        }
    }
    printf("here!!");

    // 0-n-1中最长的部分,大于结尾的长度，此时结果为结尾这段长度。
    if (maxlen >= strfix[len])
    {
        maxlen = strfix[len];
    }
    else
    // 中间长度，小于包含结尾字符的长度。再次放在next数组中找，直至找到符合的长度，或为0
    {
        int n = strfix[len];
        while (n != 0 && n > maxlen)
        {
            n = strfix[len];
        }
        maxlen = n;
    }

    if (maxlen == 0)
    {
        printf("Just a legend");
    }
    else
    {
        printf("%s", &input[len - maxlen]);
    }

    return 0;
}