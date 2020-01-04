#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class KMP {
public:
    char *source = 0;
    char *match = 0;
    KMP(char* s, char* m) {
        source = s;
        match = m;
    }
    int solve();
    void getNextArray(char* m, int* help, int num);
};

void KMP::getNextArray(char* match, int* help, int num){
    if(num == 1) {
        help[0] = -1;
        return;
    }
    help[0] = -1;
    help[1] = 0;
    // int index = 0;
    // for(int i=2; i<num; i++) {  //这里可以用while()，更简洁
    //     index = help[i-1];
    //     while(index >= 0 && match[i-1] != match[index]) {
    //         index = help[index];
    //     }
    //     help[i] = index + 1;
    // }
    int index = 2;
    int cn = 0;
    while(index < num) {
        if(match[index-1] == match[cn]) {
            help[index++] = ++cn;
        } else if(cn > 0) {
            cn = help[cn];
        } else {
            help[index++] = 0;
        }
    }
}

int KMP::solve() {
    int sLen = strlen(source);  //sizeof()处理字符串数组不好使；int source[]后使用，长度会有+1("\0")，以指针传递时，仅仅是指针长度。 可以使用strlen()进行计算，以'\0'作为结尾标志，不计算在返回值内
    int mLen = strlen(match);
    if(source == NULL || match == NULL || sLen == 0 || mLen == 0) {
        return -1;
    }
    int* help = (int*) malloc(mLen*sizeof(int));
    getNextArray(match, help, mLen);
    int p1 = 0;
    int p2 = 0;
    while(p1<sLen && p2<mLen) {
        if(source[p1] == match[p2]) {
            p1++;
            p2++;
        } else if(help[p2] == -1) {
            p1++;
        } else {
            p2 = help[p2];
        }
    }
    return p2== mLen ? p1-p2 :-1;
}

int main(int argc, char** argv) {
    char source[] = "abcdefgabadcababcdababaedfg";
    char match[] = "ababa";
    KMP kmpSolution(source, match);
    int res = kmpSolution.solve();
    printf("kmp algorithm result is %d\n", res);
    return 0;
}