#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int front, rear;
    unsigned capacity;
    int* array;
} Queue;

typedef struct Graph {
    int v;
    int** matrix;
} *Graph;

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

Graph createGraph(int v) {
    Graph graph = (Graph)malloc(sizeof(struct Graph));
    graph->v = v;

    graph->matrix = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; ++i) {
        graph->matrix[i] = (int*)calloc(v, sizeof(int));
    }

    return graph;
}

void addEdge(Graph graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
}

void BFS(Graph graph, int startVertex) {
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

        for (int i = 0; i < graph->v; ++i) {
            if (graph->matrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
            }
        }
    }

    printf("\n");

    free(visited);
    free(queue->array);
    free(queue);
}

void freeGraph(Graph graph) {
    for (int i = 0; i < graph->v; ++i) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

int main() {
    
    Graph graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    freeGraph(graph);

    return 0;
}