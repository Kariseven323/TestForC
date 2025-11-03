#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    // 从第二个元素开始，因为它之前的元素可视为已排序
    for (i = 1; i < n; i++) {
        key = arr[i]; // 这就是我们手里的“新牌”
        j = i - 1;

        // 在已排序的部分从后往前找位置
        // 如果已排序的元素比新牌大，就把它往后挪
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // 找到了位置，把新牌插进去
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}