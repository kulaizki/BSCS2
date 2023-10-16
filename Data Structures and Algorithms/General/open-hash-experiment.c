#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct Node {
    int data;
    struct Node *link;
} *LIST;

typedef LIST Dictionary[MAX];

int hash(int x);
void initialize(Dictionary D);
void insert(Dictionary D, int x);
void delete(Dictionary D, int x);
void display(Dictionary D);

int main() {

    Dictionary D;

    initialize(D);
    insert(D, 11);
    insert(D, 1);
    insert(D, 3);
    insert(D, 20);
    insert(D, 10);
    insert(D, 30);
    delete(D, 20);

    display(D);
}

int hash(int x) {
    return x % MAX;
}

void initialize(Dictionary D) {
    int x;
    for (x = 0; x < MAX; ++x) {
        D[x] = NULL;
    }
}

void insert(Dictionary D, int x) {
    int indx = hash(x);

    LIST *trav;
    for (trav = D + indx; *trav != NULL && (*trav)->data < x; trav = &(*trav)->link) {}
    LIST temp = (LIST)malloc(sizeof(struct Node));

    if (temp != NULL) {
        temp->data = x;
        temp->link = *trav;
        *trav = temp;
    }
}

void delete(Dictionary D, int x) {
    int indx = hash(x);

    LIST *trav;
    for (trav = D + indx; *trav != NULL && x != (*trav)->data; trav = &(*trav)->link) {}

    if (*trav != NULL) {
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void display(Dictionary D) {
    int x;
    for (x = 0; x < MAX; ++x) {
        LIST trav;
        for (trav = D[x]; trav != NULL; trav = trav->link) {
            printf("%d -> ", trav->data);
        }
        printf("NULL\n");
    }
}