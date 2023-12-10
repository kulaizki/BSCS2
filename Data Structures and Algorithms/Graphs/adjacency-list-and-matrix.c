#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} *Node;

typedef struct Graph {
    int v;
    Node* AL;
    int** matrix; // Adjacency matrix
} *Graph;

Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph createGraph(int v) {
    Graph graph = (Graph)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->AL = (Node*)malloc(v * sizeof(Node));
    graph->matrix = (int**)malloc(v * sizeof(int*));

    for (int i = 0; i < v; ++i) {
        graph->AL[i] = NULL;
        graph->matrix[i] = (int*)malloc(v * sizeof(int));
        for (int j = 0; j < v; ++j) {
            graph->matrix[i][j] = 0; // Initialize matrix entries to 0
        }
    }

    return graph;
}

void addEdge(Graph graph, int src, int dest) {
    // For undirected graph
    Node newNode = createNode(dest);
    newNode->next = graph->AL[src];
    graph->AL[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->AL[dest];
    graph->AL[dest] = newNode;

    // Update matrix entries
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

void printGraph(Graph graph) {
    for (int i = 0; i < graph->v; ++i) {
        printf("Adjacency list for vertex %d: ", i);

        Node current = graph->AL[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }

    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < graph->v; ++i) {
        for (int j = 0; j < graph->v; ++j) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    Graph graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}