#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct Node {
    char data[MAX];
    struct Node *next;
} *LL;

LL createNode(char *s);
void insertLLFront(LL *L, char *s);
void insertLLSorted(LL *L, char *s);
void deleteLLAllOccurrences(LL *L, char *s);
void displayLL(LL L);

int main() {
    LL L = NULL;

    insertLLFront(&L, "wex");
    insertLLFront(&L, "quas");
    insertLLFront(&L, "exort");

    insertLLSorted(&L, "abc");
    insertLLSorted(&L, "gbc");
    insertLLSorted(&L, "gbc");
    insertLLSorted(&L, "zxc");

    deleteLLAllOccurrences(&L, "gbc");

    displayLL(L); 
}

LL createNode(char *s) {
    LL temp = (LL)malloc(sizeof(struct Node));
    stpcpy(temp->data, s);
    temp->next = NULL;
    return temp;
}

void insertLLFront(LL *L, char *s) {
    LL temp = createNode(s);
    if (temp != NULL) {
        temp->next = *L;
        *L = temp;
    }
}

void insertLLSorted(LL *L, char *s) {
    LL temp = createNode(s);
    if (temp != NULL) {
        LL *trav;
        for (trav = L; *trav != NULL && strcmp(s, (*trav)->data) > 0; trav = &(*trav)->next) {}
        if (*trav != NULL) temp->next = *trav;
        *trav = temp;
    }
}

void deleteLLAllOccurrences(LL *L, char *s) {
    LL *trav, temp;
    for (trav = L; *trav != NULL;) {
        if (strcmp(s, (*trav)->data) != 0) {
            trav = &(*trav)->next;
        } else {
            temp = *trav;
            *trav = temp->next;
            free(temp);
        } 
    }
}

void displayLL(LL L) {
    while (L != NULL) {
        puts(L->data);
        L = L->next;
    }
}