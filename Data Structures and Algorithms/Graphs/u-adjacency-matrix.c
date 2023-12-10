#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int v;
    int** m;
} *Graph;

Graph createGraph(int v) {
    Graph G = (Graph)malloc(sizeof(struct Graph));
    G->v = v;

    G->m = (int **)malloc(v * sizeof(int*));

    for (int i = 0; i < v; ++i) {
        G->m[i] = (int *)malloc(v * sizeof(int));
    }

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            G->m[i][j] = 0;
        }
    }

    return G;
}

void addEdge(Graph G, int src, int dest) {
    G->m[src][dest] = 1;
    G->m[dest][src] = 1;
}

void display(Graph G) {
    printf("Adjacency Matrix\n ");
    for(int i = 0; i < G->v; ++i) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < G->v; ++i) {
        printf("%d ", i);
        for (int j = 0; j < G->v; ++j) {
            printf("%d ", G->m[i][j]);
        }
        printf("\n");
    }
}

int main() {

    Graph G = createGraph(5);

    addEdge(G, 0, 4); 
    addEdge(G, 1, 4); 
    addEdge(G, 0, 2); 

    display(G);

    // Don't forget to free the allocated memory
    for (int i = 0; i < G->v; ++i) {
        free(G->m[i]);
    }
    free(G->m);
    free(G);

    return 0;
}