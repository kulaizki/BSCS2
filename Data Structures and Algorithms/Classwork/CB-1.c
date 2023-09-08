#include <stdio.h>

#define MAX 10

typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node H[MAX];
    int Avail;
} VirtualHeap;

typedef int CLIST;

void initHeap(VirtualHeap *V);
int allocSpace(VirtualHeap *V);
void deallocSpace(int indx, VirtualHeap *V);
void insertFirst(CLIST *C, VirtualHeap *V, char elem);
void deleteElem(CLIST *C, VirtualHeap *V, char elem);
void displayList(CLIST C, VirtualHeap V);

int main() {

    CLIST C = -1;
    VirtualHeap V;

    initHeap(&V);
    insertFirst(&C, &V, 'A');
    insertFirst(&C, &V, 'B');
    insertFirst(&C, &V, 'C');
    insertFirst(&C, &V, 'B');
    deleteElem(&C, &V, 'B');

    displayList(C, V);
}

void initHeap(VirtualHeap *V) {

    int x;
    for (x = MAX - 1; x >= 0; --x) {
        V->H[x].link = x - 1;
    }

    V->Avail = MAX - 1;
}

int allocSpace(VirtualHeap *V) {

    int indx = V->Avail;
    if (indx != -1) {
        V->Avail = V->H[indx].link;
    }

    return indx;
}

void deallocSpace(int indx, VirtualHeap *V) {

    if (indx > -1 && indx < MAX) {
        V->H[indx].link = V->Avail;
        V->Avail = indx;
    }
}

void insertFirst(CLIST *C, VirtualHeap *V, char elem) {

    CLIST indx = allocSpace(V);
    if (indx != -1) {
        V->H[indx].data = elem;
        V->H[indx].link = *C;
        *C = indx;
    }
}

void deleteElem(CLIST *C, VirtualHeap *V, char elem) {

    CLIST *trav;
    for (trav = C; *trav != -1 && V->H[*trav].data != elem; trav = &V->H[*trav].link) {}
    if (*trav != -1) {
        CLIST temp = *trav;
        *trav = V->H[temp].link;
        deallocSpace(temp, V);
    }
}

void displayList(CLIST C, VirtualHeap V) {

    CLIST trav;
    for (trav = C; trav != -1; trav = V.H[trav].link) {
        printf("%c ", V.H[trav].data);
    }

    printf("\n");
}