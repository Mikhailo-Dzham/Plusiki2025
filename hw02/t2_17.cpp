#include <math.h>
#include <stdio.h>

double softPlus(double x);
double softPlus_deriv(double x);

void t2_17()
{
    printf("\n_______Task 2-17(e)_(Homw Work)_______\n");

    double x;
    printf("x = ");
    scanf("%lf", &x);

    double y = softPlus(x);
    double dydx = softPlus_deriv(x);

    printf("softPlus(%lf) = %lf\n", x, y);
    printf("softPlus'(%lf) = %lf\n", x, dydx);
}

// f(x) = ln(1 + e^x)
double softPlus(double x)
{
    return log(1 + exp(x));
}

// f'(x) = 1 / (1 + e^(-x))
double softPlus_deriv(double x)
{
    return 1.0 / (1.0 + exp(-x));
}
