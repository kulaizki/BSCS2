#include <stdio.h>
#include <stdbool.h>

int main() {

    int a[5] = {1}; // everything else is initialized to 0

    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");
    bool b[5] = {true}; // everything else is initialized to false/0

    for (int i = 0; i < 5; ++i) {
        printf("%d ", b[i]);
    }
}