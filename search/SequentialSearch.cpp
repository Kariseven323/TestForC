#include <stdio.h>

// 顺序查找函数，返回目标元素在数组中的下标，未找到返回-1
int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("请输入要查找的数字: ");
    scanf("%d", &target);
    int index = sequentialSearch(arr, n, target);
    if (index != -1) {
        printf("找到 %d ，下标为 %d\n", target, index);
    } else {
        printf("未找到 %d\n", target);
    }
    return 0;
}
