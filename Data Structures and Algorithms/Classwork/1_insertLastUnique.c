#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *LIST;

void insertLastUnique(char elem, LIST *A);
void displayList(LIST A);
void freeList(LIST A);

int main() {

    LIST L = NULL;

    insertUnique('G', &L);
    insertUnique('G', &L);
    insertUnique('D', &L);
    insertUnique('D', &L);
    insertUnique('S', &L);
    insertUnique('S', &L);
    insertUnique('C', &L);
    insertUnique('C', &L);

    displayList(L);
    freeList(L);
}

void insertLastUnique(char elem, LIST *A) {

    LIST *trav;
    for (trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav == NULL) {
        LIST temp = (LIST)malloc(sizeof(struct node));
        temp->data = elem;
        temp->link = NULL;
        *trav = temp;
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
