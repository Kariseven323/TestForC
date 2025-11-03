#include <stdio.h>

void printArray(int arr[], int size);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // 一次循环，将一个元素放到它最终的位置上
    for (i = 0; i < n - 1; i++) {
        // 假设当前未排序部分的第一个元素是最小的
        min_idx = i;
        // 遍历未排序的数组，找到真正的最小值
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 如果最小值不是当前元素，就交换它们
        if(min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}