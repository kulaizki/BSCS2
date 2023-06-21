#include <stdio.h>
#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
  //deQueue is not possible on empty queue
  dequeue();

  //enQueue 5 elements
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);

  // 6th element can't be added to because the queue is full
  enqueue(6);

  display();

  //deQueue removes element entered first i.e. 1
  dequeue();

  //Now we have just 4 elements
  display();

  return 0;
}

void enqueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void dequeue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}