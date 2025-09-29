#include <math.h>
#include <stdio.h>

double rosenbrock(double x, double y);

void t2_5()
{
    printf("\n_______Task 2-5_______\n");

    double x=1, y=2;
    printf("x=%lf, y=%lf\n", x, y);
    printf("Rosenbrock(x=%lf, y=%lf) = %lf\n", x, y, rosenbrock(x, y));

}

double rosenbrock(double x, double y)
{
    return 100 * pow((x*x - y), 2) + pow((x - 1), 2);
}
