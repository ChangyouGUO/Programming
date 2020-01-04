#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <math.h>

class NetherlandsFlag {
public:
    void Netherlands(int arr[], int* size, int num) {
        int len = *size;
        if(arr == NULL && len < 2) {
            return;
        }
        int less = -1;
        int more = len;
        int i=0;
        while(i<more) {
            if(arr[i] < num) {
                swap(arr, i++, ++less);
            } else if(arr[i] == num) {
                i++;
            } else if(arr[i] > num) {
                swap(arr, i, --more);
            }
        }       
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

    int randomSelect(int arr[], int* ActualSize) {
        srand((unsigned)time(NULL));
        int index = rand()%(*ActualSize);
        return arr[index];
    }

    void printArray(const int arr[], const int* size) {
        int len = *size;
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
        int ranValue = randomSelect(arr, ActualSize);

        printArray(arr, ActualSize);
        printf("num is %d\n", ranValue);
        Netherlands(arr, ActualSize, ranValue);
        printArray(arr, ActualSize);
        free(arr);
    }
};

int main() {
    NetherlandsFlag test1;
    test1.BasicMain();
    printf("Finish\n");
    return 0;
}
