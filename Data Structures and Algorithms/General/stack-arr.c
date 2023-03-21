#include <stdio.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data);

int main() {

    push(1);
    push(2);
    push(3);
    push(4);
    push(5); // error

    for (int i = 0; i < 4; ++i) {
        printf("%d ", stack_arr[i]);
    }
}

void push(int data) {

    if (top == MAX-1) {
        printf("Stack overflow, can't insert %d.\n", data);
        return;
    }

    top++;
    stack_arr[top] = data;
}