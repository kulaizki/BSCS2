#include <stdio.h>

int main()
{
    int x = 5;
    int *ptr1; // single pointer
    int **ptr2; // double pointer
    int ***ptr3; // triple pointer

    ptr1 = &x;
    ptr2 = &ptr1;
    ptr3 = &ptr2;

    int y = 7;
    int *rp1;
    int **rp2;

    rp1 = &y;
    rp2 = &rp1;

    int z = 1;
    int *p1 = &z;
    int **p2 = &p1;

    printf("%d\n", ***ptr3); // value of x
    printf("%d\n", **rp2); // value of y
    printf("%d", **p2); // value of z
    printf("%d\n", *p2); // address of p1

}