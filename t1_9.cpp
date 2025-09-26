#include <stdio.h>

void t1_9()
{
    printf("\n_______Task 1-9_______\n");

    double a, b;
    printf("Enter two double number to continue\n a b=");
    scanf("%lf %lf",&a, &b);

    printf("averge=%.3f\n",(a+b)/2);
    printf("harmonic=%.3e\n", 2/((1/a)+(1/b)));
}