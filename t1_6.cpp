#include <stdio.h>

void t1_6()
{
    printf("\n_______Task 1-6_______\n");

    float a;
    printf("Enter a temperature in C (Celsius) to continue\n x=");
    scanf("%f",&a);

    float f = (a * 9) /5 + 32;
    printf("F=%f\n",f);
}