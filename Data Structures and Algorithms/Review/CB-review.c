#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char data[50];
    int link;
} Node;

typedef struct {
    Node H[MAX];
    int avail;
} VHeap;

typedef int CList;

void initHeap(CList *C, VHeap *VH);
CList allocSpace(VHeap *VH);
void deallocSpace(int idx, VHeap *VH);
void insertFirst(CList *C, VHeap *VH, char *s);
void insertLast(CList *C, VHeap *VH, char *s);
void deleteAllOccurences(CList *C, VHeap *VH, char *s);
void display(CList C, VHeap VH);

int main() {
    CList C = -1;
    VHeap VH;

    initHeap(&C, &VH);
    insertLast(&C, &VH, "www");
    insertLast(&C, &VH, "yyy");
    insertLast(&C, &VH, "yyy");
    insertFirst(&C, &VH, "abc");
    insertFirst(&C, &VH, "zxc");

    deleteAllOccurences(&C, &VH, "yyy");

    display(C, VH);
}

void initHeap(CList *C, VHeap *VH) {
    int x;
    for (x = MAX - 1; x >= 0; --x) {
        VH->H[x].link = x - 1;
    }
    VH->avail = MAX - 1;
}

CList allocSpace(VHeap *VH) {
    int temp = VH->avail;
    if (temp != -1) {
        VH->avail = VH->H[temp].link;
    }
    return temp;
}

void deallocSpace(int idx, VHeap *VH) {
    if (idx > -1 && idx < MAX) {
        VH->H[idx].link = idx;
        VH->avail = idx;
    }
}

void insertFirst(CList *C, VHeap *VH, char *s) {
    int idx = allocSpace(VH);
    if (idx != -1) {
        strcpy(VH->H[idx].data, s);
        VH->H[idx].link = *C;
        *C = idx;
    }
}

void insertLast(CList *C, VHeap *VH, char *s) {
    int idx = allocSpace(VH);
    if (idx != -1) {
        CList *trav;
        for (trav = C; *trav != -1; trav = &(VH->H[*trav].link)) {}
        strcpy(VH->H[idx].data, s);
        VH->H[idx].link = -1;
        *trav = idx;
    }
}

void deleteAllOccurences(CList *C, VHeap *VH, char *s) {
    if (*C != -1) {
        CList *trav;
        for (trav = C; *trav != -1;) {
            if (strcmp(s, VH->H[*trav].data) != 0) {
                trav = &(VH->H[*trav].link);
            } else {
                CList temp = *trav;
                *trav = VH->H[temp].link;
                deallocSpace(temp, VH);
            }
        }
    }
}

void display(CList C, VHeap VH) {
    CList trav;
    for (trav = C; trav != -1; trav = VH.H[trav].link) {
        puts(VH.H[trav].data);
    }
}