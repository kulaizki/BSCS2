#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
	int data;
	struct node *link;
} *LIST;

typedef LIST Dictionary[MAX];

int Hash(int n);
void insert(Dictionary D, int e);
void initDictionary(Dictionary D);
void display(Dictionary D);
void delete(Dictionary D);
bool isMember(Dictionary D);


int main() {
	
	Dictionary D;
	
	initDictionary(D);
	
	insert(D, 48);
	insert(D, 3);
	insert(D, 4);
	insert(D, 28);
	insert(D, 108);
	
	display(D);
}

int Hash(int n) {
	
	return n % 10;
}

void insert(Dictionary D, int e) {
    int idx = Hash(e);
    LIST* trav = D + idx;

    while (*trav != NULL && (*trav)->data < e) {
        trav = &(*trav)->link;
    }

    if (*trav == NULL || (*trav)->data != e) {
        LIST temp = (LIST)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = e;
            temp->link = *trav;
            *trav = temp;
        }
    }
}
void initDictionary(Dictionary D) {
	
	int x;
	for (x = 0; x < MAX; ++x) {
		D[x] = NULL;
	}
}

void display(Dictionary D) {
	
	int x;
	for (x = 0; x < MAX; ++x) {
		LIST trav;
		for (trav = D[x]; trav != NULL; trav = trav->link) {
			printf("%d ", trav->data);
		}
	}
}

void delete(Dictionary D) {
	
}

bool isMember(Dictionary D) {
	
	
}
