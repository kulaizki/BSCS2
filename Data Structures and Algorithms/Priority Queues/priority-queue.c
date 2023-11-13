#include <stdio.h>
#include <stdlib.h>
 
#define MAX 20
 
typedef struct {
    int heap[MAX];
    int last;
} queueType, *pQueue;
 
void initQueue(pQueue q);
void displayHeap(pQueue q, int index, int level);
 
void insertMax(pQueue q, int elem);
void deleteMax(pQueue q);
void heapifyMax(int arr[], int index, int last);
    
void heapSort(int arr[], int size);
 
int main() {

    queueType myQueue;
    pQueue q = &myQueue;

    initQueue(q);
    insertMax(q, 10);
    insertMax(q, 20);
    insertMax(q, 15);
    insertMax(q, 30);
    insertMax(q, 40);
    insertMax(q, 50);
    deleteMax(q);
    displayHeap(q, 0, 0);
 
    int arr[] = {1, 6, 3, 9, 4, 69, 13, 12};
    heapSort(arr, 8);

    for (int x = 0; x < 8; x++) {
        printf("%d ", arr[x]);
    }

    printf("\n");
}
 
void initQueue(pQueue q) {

    q->last = -1;
}
 
void insertMax(pQueue q, int elem) {

    if (q->last < MAX - 1) {
        int x, temp;
        q->heap[++q->last] = elem;
        for (x = q->last; q->heap[x] > q->heap[(x - 1) / 2]; x = (x - 1) / 2) {
            temp = q->heap[x];
            q->heap[x] = q->heap[(x - 1) / 2];
            q->heap[(x - 1) / 2] = temp;
        }
    } else {
        printf("Heap is full\n");
    }
}
 
void deleteMax(pQueue q) {

    if (q->last > -1)
    {
        int lastIndex = q->last;
        int temp = q->heap[0];
        q->heap[0] = q->heap[q->last];
        q->heap[q->last--] = temp;
        heapifyMax(q->heap, 0, lastIndex);
    } else {
        printf("There's nothing to Delete\n");
    }
}
 
void heapifyMax(int arr[], int index, int last) {

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left <= last && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= last && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapifyMax(arr, largest, --last);
    }
}
 
void heapSort(int arr[], int size) {

    for (int x = size / 2 - 1; x >= 0; x--) {
        heapifyMax(arr, x, size);
    }
    for (int x = size - 1; x > 0; x--) {
        int temp = arr[0];
        arr[0] = arr[x];
        arr[x] = temp;
        heapifyMax(arr, 0, x - 1);
    }
}
 
void displayHeap(pQueue q, int index, int level) {

    if (q == NULL || index > q->last) {
        return;
    }
 
    displayHeap(q, 2 * index + 2, level + 1); // Right subtree
    for (int i = 0; i < level; i++) {
        printf("     "); // Adjust spacing for tree visualization
    }
    printf("%d\n", q->heap[index]);           // Print the current element
    displayHeap(q, 2 * index + 1, level + 1); // Left subtree
}