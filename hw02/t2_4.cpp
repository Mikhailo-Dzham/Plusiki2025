#include <math.h>
#include <stdio.h>
// y = 16x^4 + 8x^3 + 4x^2 + 2x + 1
void t2_4()
{
    printf("\n_______Task 2-4_(d)_______\n");

    double x;
    printf("x=");
    scanf("%lf", &x);

    double x2 = x * x; //1op

    printf("y=%lf", 16 * x2 * x2 + 8 * x2 * x + 4 * x2 + 2 * x + 1  ); //1op + 10op
}