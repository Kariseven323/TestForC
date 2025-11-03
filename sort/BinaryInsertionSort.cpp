#include <stdio.h>

void printArray(int arr[], int size); // 复用上面的打印函数

void binaryInsertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        int low = 0, high = i - 1;
      
        // 1. 使用二分查找找到插入位置
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // 循环结束后, low 就是 key 应该插入的位置

        // 2. 将插入位置后的所有元素后移
        for (j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        }

        // 3. 插入 key
        arr[low] = key;
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

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