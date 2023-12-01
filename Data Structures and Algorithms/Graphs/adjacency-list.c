#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} *Node;

typedef struct Graph {
    int v;
    Node* AL;
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
    for (int i = 0; i < v; ++i) {
        graph->AL[i] = NULL;
    }

    return graph;
}

void addEdge(Graph graph, int src, int dest) {

    Node newNode = createNode(dest);
    newNode->next = graph->AL[src];
    graph->AL[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->AL[dest];
    graph->AL[dest] = newNode;
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