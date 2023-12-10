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
    for (int i = 0; i < v; ++i) {
        graph->adjacencyList[i] = NULL;        
    }

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

void DFSUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph->adjacencyList[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->v * sizeof(bool));
    for (int i = 0; i < graph->v; ++i)
        visited[i] = false;

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);

    DFSUtil(graph, startVertex, visited);

    printf("\n");

    free(visited);
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

    DFS(graph, 0);

    freeGraph(graph);

    return 0;
}