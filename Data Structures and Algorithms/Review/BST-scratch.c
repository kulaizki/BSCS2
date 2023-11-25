#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Boolean;

typedef struct node {
    int e;
    struct node *LC;
    struct node *RC;
} *BST;

BST createNode(int e);
void insert(BST *B, int e);
void insertIterative(BST *B, int e);
void deleteIterative(BST *B, int e);
int min(BST B);
int minIterative(BST B);
int max(BST B);
int maxIterative(BST B);    
int sum (BST B);
Boolean search(BST B);
Boolean searchIterative(BST B);
void displayPreOrder(BST B);
void displayInOrder(BST B);
void displayPostOrder(BST B);

int main() {

    BST gdsc = NULL;

    insert(&gdsc, 1);
    insert(&gdsc, 2);
    insert(&gdsc, 2);
    insert(&gdsc, 3);
    insertIterative(&gdsc, 3);

    printf("PreOrder\n");
    displayPreOrder(gdsc);
    printf("\nInOrder\n");
    displayInOrder(gdsc);
    printf("\nPostOrder\n");
    displayPostOrder(gdsc);

    printf("\nmin: %d\n", min(gdsc));
    printf("max: %d\n", max(gdsc));
}

BST createNode(int e) {

    BST newNode = (BST)malloc(sizeof(struct node));
    newNode->e = e;
    newNode->LC = NULL;
    newNode->RC = NULL;

    return newNode;
}

void insert(BST *B, int e) {

    if (*B == NULL) {
        *B = createNode(e);
        printf("Successfully inserted [%d]\n", e);
    } else if (e < (*B)->e) {
        insert(&(*B)->LC, e);
    } else if (e > (*B)->e) {
        insert(&(*B)->RC, e);
    } else {
        printf("Invalid insert, [%d] exists\n", e);
        return;
    }
}

void insertIterative(BST *B, int e) {

    BST *trav;
    for (trav = B; *trav != NULL; trav = e < (*trav)->e ? &(*trav)->LC : &(*trav)->RC) {}

    if (trav == NULL) {
        BST temp = createNode(e);
        *trav = temp;
        printf("Successfully inserted [%d]\n", e);
    } else {
        printf("Invalid insert, [%d] exists\n", e);
    }
}

void deleteIterative(BST *B, int e) {

}

int min(BST B) {

    return (B != NULL) ? (B->LC == NULL) ? B->e : min(B->LC) : -1;
}

int minIterative(BST B) {

}

int max(BST B) {

    return (B != NULL) ? (B->RC == NULL) ? B->e : max(B->RC) : -1;
}

int maxIterative(BST B) {

}

int sum (BST B) {

    return (B == NULL) ? 0 : B->e + sum(B->LC) + sum(B->RC);
}

Boolean search(BST B) {

}

Boolean searchIterative(BST B) {

}

void displayPreOrder(BST B) {

    if (B != NULL) {
        printf("%d ", B->e);
        if (B->LC != NULL) displayPreOrder(B->LC);
        if (B->RC != NULL) displayPreOrder(B->RC);
    } else {
        printf("BST is empty");
    }
}

void displayInOrder(BST B) {

    if (B != NULL) {
        printf("%d ", B->e);
        if (B->LC != NULL) displayInOrder(B->LC);
        if (B->RC != NULL) displayInOrder(B->RC);
    } else {
        printf("BST is empty");
    }
}

void displayPostOrder(BST B) {

    if (B != NULL) {
        printf("%d ", B->e);
        if (B->LC != NULL) displayPostOrder(B->LC);
        if (B->RC != NULL) displayPostOrder(B->RC);
    } else {
        printf("BST is empty");
    }
}
