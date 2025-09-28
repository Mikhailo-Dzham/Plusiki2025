#include <stdio.h>

void t1_4()
{
    printf("\n_______Task 1-4_______\n");

    double m1 = 10, m2 = 100, r = 5;
    double y= 6.673 * (1e-11);;

    printf("F=%.9e\n", y * (m1 * m2 / (r * r)));
}