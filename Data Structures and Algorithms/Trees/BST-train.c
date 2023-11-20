#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int elem;
    struct node *LC;
    struct node *RC;
} *Node;

Node createNode(int data);
void insert(Node *root, int e);
void preOrder(Node node);
void inOrder(Node node);
void postOrder(Node node);
int sum(Node root);
bool isMember(Node root, int e);
bool isMemberIterative(Node root, int e);
void deleteMember(Node *root, int e);
int min(Node root);
int max(Node root);

int main() {

    Node tree = NULL;

    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 5);
    insert(&tree, 1);
    insert(&tree, 3);

    deleteMember(&tree, 1);
    printf("PreOrder Traversal\n");
    preOrder(tree);

    printf("\nPostOrder Traversal\n");
    postOrder(tree);
    
    printf("\nInOrder Traversal\n");
    inOrder(tree);

    printf("\nTree sum: %d\n", sum(tree));
    printf("isMember (5): %d\n", isMember(tree, 4));
    printf("isMember (6): %d\n", isMember(tree, 6));
    printf("isMember (5): %d\n", isMemberIterative(tree, 4));
    printf("isMember (6): %d\n", isMemberIterative(tree, 6));

    printf("min: %d\n", min(tree));
    printf("max: %d\n", max(tree));
}

Node createNode(int data) {

    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->elem = data;
    newNode->LC = NULL;
    newNode->RC = NULL;

    return newNode;
}

void insert(Node *root, int e) {

    if (*root == NULL) {
        *root = createNode(e);
    } else if (e < (*root)->elem) {
        insert(&(*root)->LC, e);
    } else {
        insert(&(*root)->RC, e);
    }
}

void preOrder(Node node) {

    printf("%d ", node->elem);
    if(node->LC != NULL) preOrder(node->LC);
    if(node->RC != NULL) preOrder(node->RC);
}

void inOrder(Node node) {

    if(node->LC != NULL) inOrder(node->LC);
    printf("%d ", node->elem);
    if(node->RC != NULL) inOrder(node->RC);
}

void postOrder(Node node) {

    if (node->LC != NULL) postOrder(node->LC);
    if (node->RC != NULL) postOrder(node->RC);
    printf("%d ", node->elem);

}

int sum(Node root) {

    if (root == NULL) return 0;
    return root->elem + sum(root->LC) + sum(root->RC);
}

bool isMember(Node root, int e) {

    return root == NULL ? false : e == root->elem ? true : e < root->elem ? isMember(root->LC, e) : isMember(root->RC, e);
}

bool isMemberIterative(Node root, int e) {

    while (root != NULL && e != root->elem) {
        root = e < root->elem ? root->LC : root->RC;
    }

    return root == NULL ? false : true;
}

void deleteMember(Node *root, int e) {

    for (; *root != NULL && (*root)->elem != e; root = (*root)->elem > e ? &(*root)->LC : &(*root)->RC) {}
    if (*root != NULL) {
        Node *trav, temp;
        if ((*root)->RC != NULL) {
            for (trav = &(*root)->RC; (*trav)->LC != NULL; trav = &(*trav)->LC) {}
            temp = *trav;
            (*root)->elem = temp->elem;
            *trav = (*trav)->RC;
        } else {
            temp = *root;
            *root = (*root)->LC;
        }
        free(temp);
    } else {
        printf("\nNode does not exist\n");
    }
}

int min(Node root) {

    return (root != NULL) ? (root->LC == NULL) ? root->elem : min(root->LC) : -1;
}

int max(Node root) {

    return (root != NULL) ? (root->RC == NULL) ? root->elem : max(root->RC) : -1;
}

void displayTree(Node root, int level) {

    if (root != NULL) {
        displayTree(root->RC, level + 1);

        for (int i = 0; i < level; i++) {
            printf("   ");
        }

        printf("%d\n", root->elem);
        displayTree(root->LC, level + 1);
    }
}