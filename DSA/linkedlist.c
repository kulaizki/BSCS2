#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *head = NULL;

void insertNode(Node **head, int val) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head != NULL) { newNode->next = *head; }
    *head = newNode;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    printf("Current list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }   
    printf("\n");
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
}

int main()
{
    insertNode(&head, 17);
    insertNode(&head, 7);
    displayList(head);

    insertNode(&head, 14);
    insertNode(&head, 8);
    displayList(head);

    freeList(head);
}