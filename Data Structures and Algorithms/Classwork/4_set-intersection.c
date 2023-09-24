#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *SET;


void insertFront(SET *S, int elem);
SET getIntersection(SET A, SET B);
void displaySet(SET S);

int main() {

    SET A = NULL, B = NULL, C = NULL;

    insertFront(&A, 4);
    insertFront(&A, 2);
    insertFront(&A, 1);
    insertFront(&B, 3);
    insertFront(&B, 2);
    insertFront(&B, 1);

    displaySet(A);
    displaySet(B);
    C = getIntersection(A, B);
    displaySet(C);
}

void insertFront(SET *S, int elem) {
    SET temp = (SET)malloc(sizeof(struct node));
    temp->data = elem;
    temp->link = *S;
    *S = temp;
}

SET getIntersection(SET A, SET B) {

    SET C, *cptr, temp;
    cptr = &C;

    while (A != NULL && B != NULL) {
        if (A->data < B->data) {
            A = A->link;
        } else if (B->data < A->data) {
            B = B->link;
        } else {
            temp = (SET)malloc(sizeof(struct node));
            temp->data = A->data;
            temp->link = NULL;
            if (C == NULL) {
                C = temp;
            } else {
                (*cptr)->link = temp;
            }
            cptr = &(*cptr)->link;
            A = A->link;
            B = B->link;
        }
    }

    return C;
}

void displaySet(SET S) {
    printf("[ ");
    while (S != NULL) {
        printf("%d ", S->data);
        S = S->link;
    }
    printf("]\n");
}