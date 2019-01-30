#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class Code_00 {
public:
    void function1(int arr[], int* size) {
        int len = *size;
        if(arr == NULL || len < 2 ) {
            return;
        }
        for(int e = len-1; e > 0; e--) {
            for(int i=0; i<e; i++) {
                if(arr[i] > arr[i+1]) {
                    swap(arr, i, i+1);
                }
            }
        }
    }

    // static int cmpfunc(const void* a, const void* b) {
    //     return( *(int*)a - *(int*)b );
    // }

    void comparator(int arr[], int* size) {
        int len = *size;
        // qsort(arr, *size, sizeof(int), this->cmpfunc);
        std::sort(arr, &arr[len]);
    }

    void swap(int arr[], int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
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
        int* ActualSize = NULL;
        char succeed = 1;
        for(int i=0; i<testTime; i++) {
            int* arr1 = generateRandomArray(maxSize, maxValue, ActualSize);
            int* arr2 = copyArray(arr1, ActualSize);
            function1(arr1, ActualSize);
            comparator(arr2, ActualSize);
            if( !isEqual(arr1, arr2, ActualSize)) {
                succeed = 0;
                break;
            }
        }
        printf(succeed ? "Nice！" : "Bugs1！");

        int* arr = generateRandomArray(maxSize, maxValue, ActualSize);
        printArray(arr, ActualSize);
        function1(arr, ActualSize);
        printArray(arr, ActualSize);
    }
};

int main() {
    Code_00 test1;
    test1.BasicMain();
    printf("Finish\n");
    return 0;
}
