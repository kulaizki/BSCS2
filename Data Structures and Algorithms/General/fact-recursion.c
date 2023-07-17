#include <stdio.h>

int fact(int n);

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Factorial of %d is %d\n", n, fact(n));
}

int fact(int n) {
    return (n < 2) ? 1 : n * fact(n - 1);
}