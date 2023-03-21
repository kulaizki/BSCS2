#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node **head, int x) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*head != NULL) {
        newNode->next = *head;
    }

    *head = newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Current list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void freeList(Node *head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
}

int main() {

    Node *list = NULL;
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int x;
        printf("Enter node %d: ", i);
        scanf("%d", &x);
        insertNode(&list, x);
    }

    displayList(list);
    freeList(list);
}