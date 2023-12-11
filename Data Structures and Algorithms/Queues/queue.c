#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} *Node;

typedef struct
{
    Node front;
    Node rear;
} *Queue;