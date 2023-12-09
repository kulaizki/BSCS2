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
Boolean search(BST B, int e);
Boolean searchIterative(BST B, int e);
void displayPreOrder(BST B);
void displayInOrder(BST B);
void displayPostOrder(BST B);
void displayAllOrder(BST B);

int main() {

    BST gdsc = NULL;

    insert(&gdsc, 1);
    insertIterative(&gdsc, 3);
    insertIterative(&gdsc, 7);
    insertIterative(&gdsc, 7);
    insert(&gdsc, 2);
    insert(&gdsc, 2);
    displayAllOrder(gdsc);

    printf("\nmin: %d\n", min(gdsc));
    printf("minIterative: %d\n", minIterative(gdsc));
    printf("max: %d\n", max(gdsc));
    printf("maxIterative: %d\n", maxIterative(gdsc));

    deleteIterative(&gdsc, 1);
    deleteIterative(&gdsc, 1);
    displayAllOrder(gdsc);

    printf("\nsearch: %s\n", search(gdsc, 7) ? "7 found" : "7 not found");    
    printf("search: %s\n", search(gdsc, 9) ? "9 found" : "9 not found");    
    printf("searchIterative: %s\n", searchIterative(gdsc, 7) ? "7 found" : "7 not found");    
    printf("searchIterative: %s\n", searchIterative(gdsc, 9) ? "9 found" : "9 not found");    
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
    for (trav = B; *trav != NULL && e != (*trav)->e; trav = (e < (*trav)->e) ? &(*trav)->LC : &(*trav)->RC) {}

    if (*trav == NULL) {
        BST temp = createNode(e);
        *trav = temp;
        printf("Successfully inserted [%d]\n", e);
    } else {
        printf("Invalid insert, [%d] exists\n", e);
    }
}

void deleteIterative(BST *B, int e) {

    BST *trav;
    for (trav = B; *trav != NULL && e != (*trav)->e; trav = (e < (*trav)->e) ? &(*trav)->LC : &(*trav)->RC) {}

    if (*trav != NULL) {
        BST temp = *trav;
        if (temp->LC != NULL && temp->RC != NULL) {
            for (trav = &(*trav)->RC; (*trav)->LC != NULL; trav = &(*trav)->LC) {}
            temp->e = (*trav)->e;
            temp = *trav;
        } 
        *trav = (*trav)->LC != NULL ? (*trav)->LC : (*trav)->RC;
        free(temp);
        printf("Successfully deleted [%d]\n", e);
    } else {
        printf("Invalid delete, [%d] does not exist\n", e);
    }
}

int min(BST B) {

    return (B != NULL) ? (B->LC == NULL) ? B->e : min(B->LC) : -1;
}

int minIterative(BST B) {

    int retval = -1;
    if (B != NULL) {
        for (; B->LC != NULL; B = B->LC) {} 
        retval = B->e;
    }

    return retval;
}

int max(BST B) {

    return (B != NULL) ? (B->RC == NULL) ? B->e : max(B->RC) : -1;
}

int maxIterative(BST B) {

    int retval = -1;

    if (B != NULL) {
        for (; B->RC != NULL; B = B->RC) {}
        retval = B->e;
    }

    return retval;
}

int sum (BST B) {

    return (B == NULL) ? 0 : B->e + sum(B->LC) + sum(B->RC);
}

Boolean search(BST B, int e) {

    return (B == NULL) ? FALSE : (e == B->e) ? TRUE : (e < B->e) ? search(B->LC, e) : search(B->RC, e);
}

Boolean searchIterative(BST B, int e) {

    for (; B != NULL && e != B->e; B = (e < B->e) ? B->LC : B->RC) {}

    return (B == NULL) ? FALSE : TRUE;
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

void displayInOrder(BST B) { // this prints in ascending order

    if (B != NULL) {
        if (B->LC != NULL) displayInOrder(B->LC);
        printf("%d ", B->e);
        if (B->RC != NULL) displayInOrder(B->RC);
    } else {
        printf("BST is empty");
    }
}

void displayPostOrder(BST B) {

    if (B != NULL) {
        if (B->LC != NULL) displayPostOrder(B->LC);
        if (B->RC != NULL) displayPostOrder(B->RC);
        printf("%d ", B->e);
    } else {
        printf("BST is empty");
    }
}

void displayAllOrder(BST B) {

    printf("PreOrder Traversal\n");
    displayPreOrder(B);
    printf("\nInOrder Traversal\n");
    displayInOrder(B);
    printf("\nPostOrder Traversal\n");
    displayPostOrder(B);
}