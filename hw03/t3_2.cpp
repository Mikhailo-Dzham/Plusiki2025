#include <stdio.h>

int num_reconstruct( short n1, short n2, short n3);

void t3_2()
{
    printf("\n_______Task 3-2_______\n");

    short n = 234;

    short num1 = n / 100, num2 = n/10 % 10, num3 = n % 10;
    if (num1 != num2 && num1 != num3 && num2 != num3) {
        //This is a manual variant, but I prefer it to the big if-else construction and loops because we only get 6 combinations
        printf("%hu (input)\n", num_reconstruct(num1, num2, num3));
        printf("%hu\n", num_reconstruct(num1, num3, num2));
        printf("%hu\n", num_reconstruct(num2, num1, num3));
        printf("%hu\n", num_reconstruct(num2, num3, num1));
        printf("%hu\n", num_reconstruct(num3, num2, num1));
        printf("%hu\n", num_reconstruct(num3, num1, num2));
    }
}

int num_reconstruct (short n1, short n2, short n3)
{
    return n1*100 + n2*10 + n3;
}
