#include <stdio.h>

void t3_1()
{
    printf("\n_______Task 3-1_______\n");

    short n = 234;

    short num1 = n / 100, num2 = n/10 % 10, num3 = n % 10;

    printf("hundreds: %hu\n", num1);
    printf("tens: %hu\n",  n /10);
    printf("ones: %hu\n", n);

    printf("sum: %hu\n", num1+num2+num3);

    printf("revers: %hu\n", num1 + num2 * 10 + num3 * 100);

}