#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int *B);
void heapSort(int heap[], int len);
void maxHeapify(int heap[], int index, int last);
void displayList(int heap[], int len);

int main() {

    int heap[] = {9, 5, 2, 7, 3, 8, 10, 25, 13, 1, 16};
    int heapLen = sizeof(heap) / sizeof(heap[0]);
    heapSort(heap, heapLen);
    displayList(heap, heapLen);
}

void swap(int *A, int *B) {

    int temp = *A;
    *A = *B;
    *B = temp;
}   

void heapSort(int heap[], int len) {
    
    int x;
    for (x = (len - 1) / 2; x >= 0; x--) {
        maxHeapify(heap, x, len - 1);
    }

    for (x = len - 1; x > 0; x--) {
        swap(&heap[0], &heap[x]);
        maxHeapify(heap, 0, x - 1);
    }
}

void maxHeapify(int heap[], int index, int last) {

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left <= last && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right <= last && heap[right] > heap[largest]) {
        largest = right;
    }   

    if (largest != index) {
        swap(&heap[largest], &heap[index]);
        maxHeapify(heap, largest, last - 1);
    }
}

void displayList(int heap[], int len) {

    int x;
    for (x = 0; x < len; x++) {
        printf("%d ", heap[x]);
    }
    printf("\n");
}