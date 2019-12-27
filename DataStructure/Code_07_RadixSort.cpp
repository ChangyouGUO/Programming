#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <math.h>

/*
    仅使用于非负值
*/
class Code_00 {
public:
    void RadixSort(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return;
        }
        RadixSort(arr, 0, len-1, maxbits(arr, len));
    }

    int maxbits(int arr[], int len) {
        int maxValue = INT_MIN;
        for(int i=0; i<len; i++) {
            if(arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        int bits = 0;
        while(maxValue != 0) {
            maxValue /= 10;
            bits++;
        }
        return bits;
    }

    void RadixSort(int arr[], int begin, int end, int bits) {
        int radix = 10;
        int i, j;
        int* count = (int*) malloc(radix*sizeof(int));
        memset(count, 0, radix*sizeof(int));
        int* bucket = (int*) malloc((end-begin+1)*sizeof(int));
        memset(bucket, 0, (end-begin+1)*sizeof(int));

        for(int d=1; d<=bits; d++) {
            // count 清零
            memset(count, 0, radix*sizeof(int));
            for(i=begin; i<=end; i++) {
                j = getbit(arr[i], d);
                count[j]++;
            }
            for(i=1; i<radix; i++) {
                count[i] += count[i-1];
            }
            for(i=end; i>=begin; i--) {
                j = getbit(arr[i], d);
                bucket[count[j]-1] = arr[i];  //注意这里bucket中的序号
                count[j]--;
            }
            for(i=begin, j=0; i<=end; i++, j++) {  
                arr[i] = bucket[j];  //bucket和arr中的序号不同的
            }
        }

    }

    int getbit(int val, int p) {
        return (int)(val/pow(10, p-1))%10;
    }


    static int cmpfunc(const void* a, const void* b) {
        int* x = (int*) a;   //need new pointers: x, y
        int* y = (int*) b;       
        return( *x - *y );
    }

    void comparator(int arr[], int* size) {
        int len = *size;
        qsort(arr, *size, sizeof(int), this->cmpfunc);
        // std::sort(arr, &arr[len]);
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

    int isEqual(const int arr1[], const int arr2[], int* size) {
        int len = *size;
        for(int i=0; i < len; i++) {
            if(arr1[i] != arr2[i]) 
                return 0;
        }
        return 1;
    }

    void printArray(const int arr[], const int* size) {
        int len = *size;
        for(int i=0; i<len; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void BasicMain() {
        int testTime = 500000;
        int maxSize = 100;
        int maxValue = 100;
        int size = 0;
        int* ActualSize = &size;
        char succeed = 1;
        for(int i=0; i<testTime; i++) {
            int* arr1 = generateRandomArray(maxSize, maxValue, ActualSize);
            int* arr2 = copyArray(arr1, ActualSize);
            RadixSort(arr1, ActualSize);
            comparator(arr2, ActualSize);
            if( !isEqual(arr1, arr2, ActualSize)) {
                succeed = 0;
                free(arr1);
                free(arr2);
                break;
            }
            free(arr1);
            free(arr2);
        }
        printf(succeed ? "Nice！\n" : "Bugs1！\n");

        int* arr = generateRandomArray(maxSize, maxValue, ActualSize);
        printArray(arr, ActualSize);
        RadixSort(arr, ActualSize);
        printArray(arr, ActualSize);
        free(arr);
    }
};

int main() {
    Code_00 test1;
    test1.BasicMain();
    printf("Finish\n");
    return 0;
}
