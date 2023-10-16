#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void insertLast(LIST *L, int elem);
void displayList(LIST L);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void deleteAllOccurences(LIST *L, int elem);

int main() {

    LIST L = NULL;

    insertLast(&L, 1);
    insertLast(&L, 2);
    insertLast(&L, 3);
    insertLast(&L, 4);
    insertLast(&L, 4);
    insertLast(&L, 4);
    insertLast(&L, 4);
    insertLast(&L, 5);
    insertLast(&L, 5);

    deleteFirst(&L);
    deleteLast(&L);
    deleteAllOccurences(&L, 4);

    displayList(L);

}

void insertLast(LIST *L, int elem) {

    LIST *trav;
    for (trav = L; *trav != NULL; trav = &(*trav)->link) {}
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->data = elem;
    temp->link = NULL;
    *L = temp;
}

void displayList(LIST L) {

    while (L != NULL) {
        printf("%d ", L->data);
        L = L->link;
    }
    printf("\n");
}

void deleteFirst(LIST *L) {

    if (*L != NULL) {
        LIST temp = *L;
        *L = (*L)->link;
        free(temp);
    }
}

void deleteLast(LIST *L) {

    if (*L != NULL) {
        LIST *trav, temp;
        for (trav = L; (*trav)->link->link != NULL; trav = &(*trav)->link) {}
        temp = (*trav)->link;
        (*trav)->link = NULL;
        free(temp);
    }
}

void deleteAllOccurences(LIST *L, int elem) {

    if (*L != NULL) {
        LIST *trav = L;
        while (*trav != NULL) {
            if ((*trav)->data == elem) {
                LIST temp = *trav;
                *trav = (*trav)->link;
                free(temp);
            } else {
                trav = &(*trav)->link;
            }
        }
    }
}