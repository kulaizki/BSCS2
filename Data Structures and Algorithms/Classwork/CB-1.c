#include <stdio.h>

#define MAX 5

typedef struct {
    char data;
    int link;
} NodeType;

typedef struct {
    NodeType Nodes[MAX];
    int Avail;
} VirtualHeap;

typedef int CLIST;

void initList(VirtualHeap *V);
int allocSpace(VirtualHeap *V);
void deallocSpace(int indx, VirtualHeap *V);


int main() {

    CLIST C = MAX - 1;

}