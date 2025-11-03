#include <stdio.h>

void printArray(int arr[], int size);
void swap(int *a, int *b);

// 这个函数负责分区，并返回基准元素的最终索引（双指针法）
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;
    while (left < right) {
        // 从右往左找小于pivot的
        while (left < right && arr[right] >= pivot) right--;
        // 从左往右找大于pivot的
        while (left < right && arr[left] <= pivot) left++;
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    // 最后把pivot放到中间
    swap(&arr[low], &arr[left]);
    return left;
}

// 快速排序主函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi 是分区后的基准元素索引
        int pi = partition(arr, low, high);

        // 分别对基准左右两边的子数组进行排序，注意pi元素已经在正确位置
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}