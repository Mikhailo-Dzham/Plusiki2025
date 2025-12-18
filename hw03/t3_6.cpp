#include <cmath>
#include <stdio.h>

double max(double n1, double n2, double n3);
double min(double n1, double n2, double n3);

void t3_6()
{
    printf("\n_______Task 3-6_______\n");

    double a1=-100, b1=-3.999999, c1=2;
    double a = fabs(a1), b = fabs(b1), c = fabs(c1);

    printf("%lf\n", max(a, b, c));
    printf("%lf\n", min(a, b, c));
}

double min(double n1, double n2, double n3)
{
    double min_num = n1;
    if (min_num > n2)
    {
        min_num = n2;
    }

    if (min_num > n3) {
        min_num = n3;
    }
    return min_num;
}

double max(double n1, double n2, double n3)
{
    double max_num = n1;
    if (max_num < n2)
    {
        max_num = n2;
    }

    if (max_num < n3) {
    max_num = n3;
    }
    return max_num;
}

