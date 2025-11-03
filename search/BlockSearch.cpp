#include <stdio.h>

// 分块查找（索引顺序查找）
// blockIndex: 每块的最大值数组，blockSize: 每块元素个数
// 返回目标值在原数组中的下标，未找到返回 -1
int blockSearch(int arr[], int n, int blockIndex[], int blockCount, int blockSize, int target) {
    int block = -1;
    // 1. 用折半查找在索引表中查找目标属于哪一块
    int low = 0, high = blockCount - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (target <= blockIndex[mid]) {
            // 还要判断是不是前一块的最大值更小
            if (mid == 0 || target > blockIndex[mid - 1]) {
                block = mid;
                break;
            } else {
                high = mid - 1;
            }
        } else {
            low = mid + 1;
        }
    }
    if (block == -1) return -1; // 不在任何块中
    // 2. 在线性表的对应块中顺序查找
    int start = block * blockSize;
    int end = (block + 1) * blockSize;
    if (end > n) end = n;
    for (int i = start; i < end; i++) {
        if (arr[i] == target) return i;
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
    // 假设原始数据已分块并有序，每块大小为3
    int arr[] = {2, 4, 5, 8, 9, 12, 16, 18, 20, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int blockSize = 3;
    int blockCount = (n + blockSize - 1) / blockSize;
    int blockIndex[blockCount];
    // 构建每块的最大值索引表
    for (int i = 0; i < blockCount; i++) {
        int end = (i + 1) * blockSize - 1;
        if (end >= n) end = n - 1;
        blockIndex[i] = arr[end];
    }
    printf("Array: ");
    printArray(arr, n);
    printf("Block index: ");
    printArray(blockIndex, blockCount);
    int target = 18;
    printf("Search target: %d\n", target);
    int result = blockSearch(arr, n, blockIndex, blockCount, blockSize, target);
    if (result != -1) {
        printf("Found at index: %d\n", result);
    } else {
        printf("Not found.\n");
    }
    return 0;
}
