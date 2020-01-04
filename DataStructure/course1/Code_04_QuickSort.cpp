#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class Code_00 {
public:
    void QuickSort(int arr[], int* size) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return;
        }
        QuickSort(arr, 0, len-1);       
    }

    void QuickSort(int arr[], int l, int r) {
        srand((unsigned)time(NULL));
        if(l < r) {
            swap(arr, l+rand()%(r-l) + 1, r);
            int* p = partition(arr, l, r);
            QuickSort(arr, l, p[0]);
            QuickSort(arr, p[1], r);
            free(p);
        }
    }

    int* partition(int arr[], int l, int r) {
        int less = l-1;
        int more = r;  // r位置是划分值
        while( l < more ) {
            if(arr[l] < arr[r]){
                swap(arr, ++less, l++);
            }
            else if(arr[l] > arr[r]) {
                swap(arr, --more, l);  //从最右侧交换数值，交换到中间的数还没有被判断，所以是l
            } else {
                l++;
            }
        }
        swap(arr, more++, r);  //将末尾的比较数值交换到等于与大于数值的边界处
        int* p = (int *) malloc(2 * sizeof(int));
        p[0] = less;
        p[1] = more;
        return p;
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
            QuickSort(arr1, ActualSize);
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
        QuickSort(arr, ActualSize);
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
