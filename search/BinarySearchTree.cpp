#include <stdio.h>
#include <stdlib.h>

// 二叉排序树结点结构体
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

// 创建新结点
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 插入结点
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    // 相等时不插入重复元素
    return root;
}

// 查找结点
TreeNode* search(TreeNode* root, int target) {
    while (root != NULL) {
        if (target == root->val) return root;
        else if (target < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// 中序遍历
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

// 释放树
void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 4, 7, 9, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    int target = 7;
    printf("Search target: %d\n", target);
    TreeNode* res = search(root, target);
    if (res) {
        printf("Found: %d\n", res->val);
    } else {
        printf("Not found.\n");
    }
    freeTree(root);
    return 0;
}
