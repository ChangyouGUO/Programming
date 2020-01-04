#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <math.h>

class CodeMaxGap {
public:
    int MaxGap(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return -1;
        }
        
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i=0; i<len; i++) {
            max = arr[i] > max ? arr[i] : max;
            min = arr[i] < min ? arr[i] : min;
        }
        if(max == min) {
            return 0;
        }
        char* hasNum = (char*) malloc((len+1)*sizeof(char));
        memset(hasNum, 0, (len+1)*sizeof(char));
        int* maxs = (int*) malloc((len+1)*sizeof(int));
        int* mins = (int*) malloc((len+1)*sizeof(int));
        int index = 0;
        for(int i=0; i<len; i++) {
            index = bucket(arr[i], len, min, max);
            maxs[index] = hasNum[index] == 1 ? (arr[i]>maxs[index] ? arr[i] : maxs[index]) : arr[i];
            mins[index] = hasNum[index] == 1 ? (arr[i]<mins[index] ? arr[i] : mins[index]) : arr[i];
            hasNum[index] = 1;
        }
        int res = 0;
        int lastMax = maxs[0];
        for(int i=1; i<=len; i++) {
            if(hasNum[i] == 1) {
                res = res > mins[i]-lastMax ? res : mins[i]-lastMax;
                lastMax = maxs[i];
            }
        }
        printf("mins\n");
        printArray(mins, len+1);
        printf("maxs\n");
        printArray(maxs, len+1);
        free(hasNum);
        free(maxs);
        free(mins);
        return res;
    }

    int bucket(int value, int len, int min, int max) {
        return (int)(value-min)*len/(max-min);
    }

    void swap(int arr[], int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;

        // arr[a] = arr[a] ^ arr[b];
        // arr[b] = arr[a] ^ arr[b];
        // arr[a] = arr[a] ^ arr[b];
        return;
    }

    int* generateRandomArray(int maxSize, int maxValue, int* ActualSize) {
        srand((unsigned)time(NULL));
        int size = rand() % maxSize +1;
        *ActualSize = size;
        int* arr = (int *) malloc(size*sizeof(int));
        for(int i = 0; i<size; i++) {
            arr[i] = rand() % maxValue + 1;
        }
        return arr;
    }

    void printArray(const int arr[], int len) {
        for(int i=0; i<len; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void BasicMain() {
        int maxSize = 100;
        int maxValue = 100;
        int size = 0;
        int* ActualSize = &size;
        int* arr = generateRandomArray(maxSize, maxValue, ActualSize);

        printArray(arr, size);
        printf("max gap is %d\n", MaxGap(arr, ActualSize));
        free(arr);
    }
};

int main() {
    CodeMaxGap test1;
    test1.BasicMain();
    printf("Finish\n");
    return 0;
}
