#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void printTree(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

int getTreeSum(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->data + getTreeSum(node->left) + getTreeSum(node->right);
}

int main() {

    struct TreeNode* root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    printf("In-order traversal of binary tree: ");
    printTree(root);
    printf("\n");

    printf("Sum of binary tree: ");
    printf("%d", getTreeSum(root));

    return 0;
}