#include <math.h>
#include <stdio.h>

void t2_3()
{
    printf("\n_______Task 2-3_______\n");

    double a=4, b=3, c=5, p = (a + b + c)/2;

    printf("a: %f\nb: %f\nc: %f\nS: %f\n", a, b, c, sqrt(p * (p - a) * (p - b) * (p - c)));
}