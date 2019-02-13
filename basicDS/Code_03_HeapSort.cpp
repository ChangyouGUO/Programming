/*
    heapsort, basic lession 2, 77minutes.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class Code_00 {
public:
    void HeapSort(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return;
        }
        HeapInsert(arr, 0, len);  //len前期为整体数量长度，后期为最后下标位置
        swap(arr, 0, --len);
        while(len > 0) {
            heapify(arr, 0, len);
            swap(arr, 0, --len);
        }
    }

    void HeapInsert(int arr[], int head, int len) {
        for(int index=head; index<len; index++) {
            while(index > 0 && arr[(index-1)/2] < arr[index]) {
                swap(arr, (index-1)/2, index);
                index = (index-1)/2;
            }
        }
    }   

    void heapify(int arr[], int index, int len) {
        int left = index * 2 + 1;
        while( left < len ) {
            int largest = left+1 < len && arr[left] < arr[left+1] ? left+1 : left;
            largest = arr[largest] > arr[index] ? largest : index;
            if(largest == index) {
                break;
            } 
            swap(arr, index, largest);
            index = largest;
            left = index*2 +1;
        }
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
            HeapSort(arr1, ActualSize);
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
        HeapSort(arr, ActualSize);
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
