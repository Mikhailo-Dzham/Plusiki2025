#include <stdio.h>
#include <math.h>

void t1_20()
{
    printf("\n_______Task 1-20_(Home Work)________\n");

    double a, b, c;
    printf("Enter three numbers to continue\n");
    scanf("A==%lf B==%lf C==%lf", &a, &b, &c);

    printf("averge=%.6e\n",(a+b+c)/3);
    printf("harmonic=%.6e\n", 3/((1/a)+(1/b)+(1/c)));
}