#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Code_00 {
public:
    void function1(int arr[], int len) {
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

    void swap(int arr[], int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        return;
    }

    int generateRandomArray(maxSize, maxValue) {

    }

    void BasicMain(int arr[], int n) {
        int testTime = 500000;
        int maxSize = 100;
        int maxValue = 100;
        char succeed = 1;
        for(int i=0; i<testTime; i++) {
            int arr1[] = generateRandomArray(maxSize, maxValue);
            int arr2[] = copyArray(arr1);
            function1(arr1);
            comparator(arr2);
            if( !isEqual(arr1, arr2)) {
                succeed = 0;
                break;
            }
        }
        printf(succeed ? "Nice！" : "Bugs1！");

        int arr[] = generateRandomArray(maxSize, maxValue);
        printArray(arr);
        function1(arr);
        printArray(arr);
    }
};
