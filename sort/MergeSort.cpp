#include <stdio.h>
#include <stdlib.h> // for malloc and free

void printArray(int arr[], int size);

// 合并两个子数组 L 和 M 到 arr
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // 拷贝数据到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回到 arr[left..right]
    i = 0; // L[] 的初始索引
    j = 0; // R[] 的初始索引
    k = left; // 合并后数组的初始索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 剩余的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 剩余的元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
  
    // 释放临时数组内存
    free(L);
    free(R);
}

// 归并排序主函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 找到中间点，防止 (left+right) 溢出
        int mid = left + (right - left) / 2;

        // 递归地排序左右两半
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的两半
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

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