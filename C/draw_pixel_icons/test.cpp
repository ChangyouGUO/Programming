// #include <iostream>
#include <math.h>
#include <stdio.h>
// using namespace std;
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Width (1280)
#define Height (720)

void moPutDeviation(int last_x, int last_y, int x, int y, int right)
{
    int value = x-last_x >0 ? x-last_x: last_x -x;
    if(value >127 || y < 16) {
        return;
    }
    char deviation = x-last_x;
    printf("%d,", last_y);
    printf("%d, %d, ", last_x, x);
    printf("%d,--", deviation);
}

void line(int width, int height, int nLeft, int nTop, int nRight, int nBottom, int RightLane) {
    int x, y, last_x, last_y;
    int nX1, nX2, nY1, nY2;
    float fDyx = 10000.0, fDxy = 10000.0;
    if (nTop - nBottom != 0) fDxy = 1.0f * (nLeft - nRight) / (nTop - nBottom);
    if (nLeft - nRight != 0) fDyx = 1.0 * (nTop - nBottom) / (nLeft - nRight);

    last_x = nLeft;
    last_y = nTop;
    nX1 = min(nLeft, nRight);
    nX2 = max(nLeft, nRight);

    nX1 = max(0, nX1);
    nX2 = min(width - 1, nX2);

    nY1 = min(nTop, nBottom);
    nY2 = max(nTop, nBottom);

    nY1 = max(0, nY1);
    nY2 = min(height - 1, nY2);

    if (fabs(fDxy) < fabs(fDyx)) {  //以y为自变量
        for (y = nY1+1; y <= nY2; y++) {
            x = nRight + (y - nBottom) * fDxy;
            if (x >= nX1 && x <= nX2) {
                moPutDeviation(last_x, last_y, x, y, RightLane);
                last_x = x;
            }  
        }   
    } else {    //以x为自变量
        if(nX1 == nLeft) {
            for (x = nX1+1; x <= nX2; x++) {
                y = nBottom + (x - nRight) * fDyx;
                if(y != last_y){
                    last_y = y;
                    last_x = x-1;
                }
                if (y >= nY1 && y <= nY2) {
                    moPutDeviation(last_x, last_y, x, y, RightLane);
                }
            }
        } else {
            for (x = nX2-1; x>=nX1; x--) {
                y = nBottom + (x - nRight) * fDyx;
                if(y != last_y){
                    last_y = y;
                    last_x = 640;
                }
                if (y >= nY1 && y <= nY2) {
                    moPutDeviation(last_x, last_y, x, y, RightLane);
                    last_x = x;
                }
            }
        }
    }
}

int main()
{
    // line(Width, Height, Width/2, Height/4, 
    //                     1250, Height*2/4, 1);
    line(Width, Height, Width/2, Height/4, 
                           Width/10, Height*2/4, 1);

    printf("--------\n");
    char isWarning = 0;
    isWarning = 2;
    if(isWarning == 1) {
        printf("isWarning == 1\n");
    }
    else if(isWarning == 2) {
        printf("isWarning == 2\n");
    }
    return 0;
}