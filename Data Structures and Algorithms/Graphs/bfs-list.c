#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int v;
    Node** adjacencyList;
} Graph;

typedef struct Queue {
    int front, rear;
    unsigned capacity;
    int* array;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int v) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->v = v;

    graph->adjacencyList = (Node**)malloc(v * sizeof(Node*));
    for (int i = 0; i < v; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return item;
}

void BFS(Graph* graph, int startVertex) {
    Queue* queue = createQueue(graph->v);

    bool* visited = (bool*)malloc(graph->v * sizeof(bool));
    for (int i = 0; i < graph->v; ++i)
        visited[i] = false;

    enqueue(queue, startVertex);
    visited[startVertex] = true;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                enqueue(queue, adjVertex);
                visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(visited);
    free(queue->array);
    free(queue);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->v; ++i) {
        Node* current = graph->adjacencyList[i];
        while (current) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    freeGraph(graph);

    return 0;
}