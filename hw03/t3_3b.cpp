#include <stdio.h>

void t3_3b()
{
    printf("\n_______Task 3-3(b)_______\n");

    long a, b, c;
    printf("second three (up to 2^21:");
    scanf("%ld,%ld,%ld", &a, &b, &c);

    long long product = (long long)a * b * c;
    printf("Product %ld * %ld * %ld= %lld\n", a, b, c, product);
}