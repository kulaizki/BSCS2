#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int value) {
    Node* result = (Node*) malloc(sizeof(Node));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->data = value;
    }
    return result;
}

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; ++i) {
        printf("\t");
    }
}

void printTreeRec(Node* root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("---<empty>--\n");
        return;
    }
    
    printTabs(level);
    printf("Value = %d\n", root->data);
    printTabs(level);
    printf("left\n");

    printTreeRec(root->left, level+1);
    printTabs(level);
    printf("right\n");

    printTreeRec(root->right, level+1);

    printTabs(level);
    printf("done\n");
}

void displayTree(Node* root) {
    printTreeRec(root, 0);
}

int main()
{
    Node* n1 = createNode(10);
    Node* n2 = createNode(11);
    Node* n3 = createNode(12);
    Node* n4 = createNode(13);
    Node* n5 = createNode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    displayTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}