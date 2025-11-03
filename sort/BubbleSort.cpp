#include <stdio.h>

void printArray(int arr[], int size);
void swap(int *xp, int *yp);

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        // 引入一个标志位，用于优化
        int swapped = 0;
        // 每一轮都把当前未排序部分的最大值“冒泡”到最后
        // -i 是因为每轮过后，末尾的 i 个元素已经是有序的了
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        // 如果在一轮中没有发生任何交换，说明数组已经有序
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

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

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}