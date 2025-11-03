#include <stdio.h>
#include <stdlib.h>

// AVL树结点结构体
struct AVLNode {
    int val;
    struct AVLNode *left, *right;
    int height;
};

typedef struct AVLNode AVLNode;

// 获取节点高度
int height(AVLNode* node) {
    return node ? node->height : 0;
}

// 创建新节点
AVLNode* newNode(int val) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->val = val;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// 右旋
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    return x;
}

// 左旋
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    return y;
}

// 获取平衡因子
int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// 插入节点
AVLNode* insert(AVLNode* node, int val) {
    if (node == NULL) return newNode(val);
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node; // 不插入重复值
    node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;
    int balance = getBalance(node);
    // LL型
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
    // RR型
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
    // LR型
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL型
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// 查找节点
AVLNode* search(AVLNode* root, int target) {
    while (root != NULL) {
        if (target == root->val) return root;
        else if (target < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// 中序遍历
void inorder(AVLNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

// 释放树
void freeTree(AVLNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    AVLNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    int target = 25;
    printf("Search target: %d\n", target);
    AVLNode* res = search(root, target);
    if (res) {
        printf("Found: %d\n", res->val);
    } else {
        printf("Not found.\n");
    }
    freeTree(root);
    return 0;
}
