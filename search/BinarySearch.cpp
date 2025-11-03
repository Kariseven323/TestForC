#include <stdio.h>

// 折半查找（二分查找）
// 返回目标值在数组中的下标，未找到返回 -1
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    printf("Array: ");
    printArray(arr, n);
    printf("Search target: %d\n", target);
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Found at index: %d\n", result);
    } else {
        printf("Not found.\n");
    }
    return 0;
}
