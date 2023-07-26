#include <stdio.h>
#include <stdlib.h>

char* intToBinary(int n) {
    char* binary = (char *)malloc(sizeof(char) * 33);
    binary[32] = '\0';

    for (int i = 31; i >= 0; --i) {
        binary[i] = (n & 1) + '0';
        n >>= 1;
    }

    return binary;
}

int main() {

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
     
    printf("%d in binary is: %s\n", n, intToBinary(n));
    printf("%d will be the value of n when right shifted\n", n >>= 1);
    printf("%d in binary is: %s", n, intToBinary(n));
}