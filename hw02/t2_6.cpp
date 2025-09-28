#include <math.h>
#include <stdio.h>

double length(double x1, double y1, double x2, double y2);
double heron(double a, double b, double c);

void t2_6()
{
    printf("\n_______Task 2-6_______\n");

    double xA, yA, xB, yB, xC, yC;
    printf("A =");
    scanf("%lf %lf", &xA, &yA);
    printf("B =");
    scanf("%lf %lf", &xB, &yB);
    printf("C =");
    scanf("%lf %lf", &xC, &yC);

    double ab = length(xA, yA, xB, yB),
    bc = length(xB, yB, xC, yC),
    ac = length(xC, yC, xA, yA);

    printf("S ABC = %lf\n", heron(ab, bc, ac));


}

double heron(double a, double b, double c)
{
    double p = (a + b + c)/2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


double length(double x1, double y1, double x2, double y2)
{
    double part1 = x1 - x2, part2 = y1 - y2;
    return sqrt(part1 * part1 + part2 * part2);
}
