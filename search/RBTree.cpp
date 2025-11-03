#include <stdio.h>
#include <stdlib.h>

// 红黑树结点颜色
#define RED 0
#define BLACK 1

// 红黑树结点结构体
struct RBTNode {
    int val;
    int color;
    struct RBTNode *left, *right, *parent;
};

typedef struct RBTNode RBTNode;

// 创建新结点
RBTNode* newNode(int val) {
    RBTNode* node = (RBTNode*)malloc(sizeof(RBTNode));
    node->val = val;
    node->color = RED; // 新插入节点为红色
    node->left = node->right = node->parent = NULL;
    return node;
}

// 左旋
void leftRotate(RBTNode** root, RBTNode* x) {
    RBTNode* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// 右旋
void rightRotate(RBTNode** root, RBTNode* y) {
    RBTNode* x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->parent = y->parent;
    if (!y->parent) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// 插入修正
void insertFixup(RBTNode** root, RBTNode* z) {
    while (z->parent && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTNode* y = z->parent->parent->right;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            RBTNode* y = z->parent->parent->left;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// 插入节点
void insert(RBTNode** root, int val) {
    RBTNode* z = newNode(val);
    RBTNode* y = NULL;
    RBTNode* x = *root;
    while (x) {
        y = x;
        if (val < x->val) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (!y) *root = z;
    else if (val < y->val) y->left = z;
    else y->right = z;
    insertFixup(root, z);
}

// 查找节点
RBTNode* search(RBTNode* root, int target) {
    while (root) {
        if (target == root->val) return root;
        else if (target < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// 中序遍历
void inorder(RBTNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d(%s) ", root->val, root->color == RED ? "R" : "B");
        inorder(root->right);
    }
}

// 释放树
void freeTree(RBTNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int arr[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    RBTNode* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(&root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    int target = 25;
    printf("Search target: %d\n", target);
    RBTNode* res = search(root, target);
    if (res) {
        printf("Found: %d\n", res->val);
    } else {
        printf("Not found.\n");
    }
    freeTree(root);
    return 0;
}
