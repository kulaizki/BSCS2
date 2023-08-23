#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *LIST;

void insertFront(char elem, LIST *A);
void insertUnique(char elem, LIST *A);
void deleteAllOccurences(char elem, LIST *A);
void displayList(LIST A);
void freeList(LIST A);

int main() {

    LIST L = NULL;

    insertFront('X', &L);
    insertFront('X', &L);
    insertUnique('G', &L);
    insertUnique('G', &L);
    insertUnique('D', &L);

    insertFront('Y', &L);
    insertUnique('D', &L);
    insertUnique('S', &L);
    insertUnique('S', &L);
    insertUnique('C', &L);
    insertUnique('C', &L);
    deleteAllOccurences('X', &L);
    deleteAllOccurences('g', &L);

    displayList(L);
    freeList(L);
}

void insertFront(char elem, LIST *A) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->data = elem;
    temp->link = *A;
    *A = temp;
}

void insertUnique(char elem, LIST *A) {

    LIST *trav;
    for (trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav == NULL) {
        LIST temp = (LIST)malloc(sizeof(struct node));
        temp->data = elem;
        temp->link = NULL;
        *trav = temp;
    }    
}

void deleteAllOccurences(char elem, LIST *A) {

    LIST *trav = A, temp;
    while (*trav != NULL) {
        if ((*trav)->data == elem) {
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
}

void displayList(LIST A) {

    while (A != NULL) {
        printf("%c ", A->data);
        A = A->link;
    }
}

void freeList(LIST A) {

    while (A != NULL) {
        LIST temp = A;
        A = A->link;
        free(temp);
    }
}

