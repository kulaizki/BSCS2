#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *SET;

SET intersection(SET A, SET B) {

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

int main() {

    
}