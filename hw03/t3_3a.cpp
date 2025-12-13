#include <stdio.h>

void t3_3a()
{
    printf("\n_______Task 3-3(a)_______\n");

    short a, b, c;
    printf("first three (up to 2^10:");
    scanf("%hd,%hd,%hd", &a, &b, &c);

    int product = a * b * c;
    printf("Product %hd * %hd * %hd= %d\n", a, b, c, product);
}