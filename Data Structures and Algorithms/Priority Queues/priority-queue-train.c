#include "_header.h"

void swap(int *a, int *b) {

}

void Heapify(pQueue *q, int index) {

}

void Insert(int elem, pQueue *q){

}

void Display(pQueue q){

}

int LeftChild(int index) {

}

int RightChild(int index) {

}

int SmallestChild(pQueue q, int index) {

}

int DeleteMin(pQueue *q) {

}

void Initialize(pQueue *q) {

}

void MakeNull(pQueue *q){

}

//heap sort psuedo
// turn an array into a heap
// deletemin from your heap
// store it in an array

void heapsort(int *arr, int size) {

}

int main(void) {

    int arr [9]= {9,2,18,23,5,1,8,27,7};
    pQueue q;

    // Initialize(&q);

    // Insert(3, &q);
    // Insert(10, &q);
    // Insert(2, &q);
    // Insert(39, &q);
    // Insert(9, &q);
    // Insert(15, &q);
    // Insert(23, &q);
    // Insert(4, &q);
    // Insert(1, &q);
    // Insert(20, &q);
    // Insert(7, &q);
    // Insert(15, &q);
    // Insert(0, &q);

    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);

    // Display(q);
    heapsort(arr, 9);
    for(int x = 0; x < 9; x ++) {
        printf("%d ", arr[x]);
    }
    
    return 0;
}