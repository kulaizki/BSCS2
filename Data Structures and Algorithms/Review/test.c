#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void insertFront(LIST *L, int x);
void insertLast(LIST *L, int x);
void deleteFront(LIST *L);
void deleteLast(LIST *L);
void deleteElem(LIST *L, int x);
void deleteAllOccurences(LIST *L, int x);
int search(LIST L, int x);
void display(LIST L);
void freeList(LIST *L);

int main() {

    LIST L = NULL;

    insertLast(&L, 1);
    insertFront(&L, 2);
    insertFront(&L, 3);
    insertLast(&L, 4);
    insertLast(&L, 4);
    insertLast(&L, 4);
    display(L);
    printf("%d\n", search(L, 4));
    printf("%d\n", search(L, 5));
    deleteAllOccurences(&L, 4);
    deleteLast(&L);
    deleteElem(&L, 2);
    display(L);
    freeList(&L);
}

void insertFront(LIST *L, int x) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->data = x;
        temp->link = *L;
        *L = temp;
    }
}

void insertLast(LIST *L, int x) {
    LIST *trav;
    for (trav = L; *trav != NULL; trav = &(*trav)->link) {}
    LIST temp = (LIST)malloc(sizeof(struct node));
    
    if (temp != NULL) {
        temp->data = x;
        temp->link = NULL;
        *trav = temp;
    }
}

void deleteFront(LIST *L) {
    if (*L != NULL) {
        LIST temp = *L;
        *L = temp->link;
        free(temp); 
    }
}

void deleteLast(LIST *L) {
    if (*L != NULL) {
        LIST *trav, temp;
        for (trav = L; (*trav)->link != NULL; trav = &(*trav)->link) {}
        temp = *trav;
        *trav = temp->link; 
        free(*trav); 
    }
}

void deleteElem(LIST *L, int x) {
    LIST *trav;
    for (trav = L; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}
    if (*trav != NULL) {
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void deleteAllOccurences(LIST *L, int x) {
    LIST *trav = L;
    while (*trav != NULL) {
        if ((*trav)->data == x) {
            LIST temp = *trav;
            *trav = temp->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
}

int search(LIST L, int x) {
    LIST trav;
    for (trav = L; trav != NULL && trav->data != x; trav = trav->link) {}
    return (trav != NULL) ? 1 : 0;
}

void display(LIST L) {
    while (L != NULL) {
        printf("%d -> ", L->data);
        L = L->link;
    }
    printf("NULL\n");
}

void freeList(LIST *L) {
    while (*L != NULL) {
        LIST temp = *L;
        *L = (*L)->link;
    }
}