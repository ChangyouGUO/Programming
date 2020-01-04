#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <math.h>

class CodeSmallSum {
public:
    int SmallSum(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return -1;
        }
        return MergeSort(&arr[0], 0, len-1);
    }

    int MergeSort(int arr[], int l, int r) {
        if(l == r) {
            return 0;
        }
        int mid = l + (r-l)/2;
        return MergeSort(&arr[0], l, mid) + MergeSort(&arr[0], mid+1, r) + Merge(&arr[0], l, mid, r);
    }

    int Merge(int arr[], int l, int mid, int r) {
        int* help = (int* ) malloc((r-l+1)*sizeof(int));
        memset(help, 0, (r-l+1)*sizeof(int));
        int i = 0;
        int p1 = l;         //注意这里的命名方式
        int p2 = mid+1;
        int res = 0;
        while(p1<=mid && p2<=r) {
            if(arr[p1]<arr[p2]) {
                res += arr[p1]*(r-p2+1);
                help[i++] = arr[p1++];
            } else {
                help[i++] = arr[p2++];
            }
        }
        while(p1<=mid) {
            help[i++] = arr[p1++];
        }
        while(p2<=r) {
            help[i++] = arr[p2++];
        }
        for(i=0; i<r-l+1; i++) {
            arr[l+i] = help[i];   //为啥不用l++，因为循环的边界条件用的是r-l+1，不能在循环中使用l++
        }
        return res;
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

    int* copyArray(const int* arr, const int* size) {
        int len = *size;
        int *arr2 = (int*)malloc(len * sizeof(int));
        for(int i=0; i<len; i++) {
            arr2[i] = arr[i];
        }
        return arr2;
    }

    int comparator(const int* arr, const int*size) {
        int len = *size;
        if(arr == NULL || len <2) {
            return 0;
        }
        int res = 0;
        for(int i=0; i<len; i++) {
            for(int j=0; j<i; j++) {
                if(arr[j] < arr[i]) {
                    res += arr[j];
                }
            }
        }
        return res;
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
        int* arr1 = generateRandomArray(maxSize, maxValue, ActualSize);
        int* arr2 = copyArray(&arr1[0], ActualSize);

        printArray(arr1, size);
        printf("max gap is %d\n", SmallSum(&arr1[0], ActualSize));
        printf("standard answer is %d\n", comparator(&arr2[0], ActualSize));
        free(arr1);
        free(arr2);
    }
};

int main() {
    CodeSmallSum test1;
    test1.BasicMain();
    printf("Finish\n");
    return 0;
}
