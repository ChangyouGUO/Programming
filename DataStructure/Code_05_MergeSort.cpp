#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class Code_00 {
public:
    void MergeSort(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return;
        }
        MergeSort(arr, 0, len-1);       
    }

    void MergeSort(int arr[], int l, int r) {
        if(l == r) {
            return;
        }
        int mid = l + ((r-l) >> 1);  //没有直接相加，防止数值移除
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }

    void Merge(int arr[], int l, int mid, int r) {
        int* help = (int*) malloc((r-l+1)*sizeof(int));  //准备辅助数组
        int i=0;  //新数组的index
        int p1 = l;
        int p2 = mid + 1;
        while(p1 <= mid && p2 <= r ) {
            help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        }       
        while(p1<=mid) {
            help[i++] = arr[p1++];
        }
        while(p2<=r) {
            help[i++] = arr[p2++];
        }
        for(int j=0; j<i; j++) {
            arr[l+j] = help[j];
        }
        free(help);       
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
            MergeSort(arr1, ActualSize);
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
        MergeSort(arr, ActualSize);
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
