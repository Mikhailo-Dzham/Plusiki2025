// Кола задаються через координати центру та радіус (x, y, r)
// відстань між точками d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
// Тоді два кола перетинаються якщо:
// 1. d <= r1 + r2
// 2. d >= |r1 - r2|

#include <stdio.h>
#include <math.h>

double d(double x1, double y1, double x2, double y2);
void do_they_intersect(double x1, double y1, double r1, double x2, double y2, double r2);

void t3_16()
{
    printf("\n_______Task 3-16_______\n");

    double x1, y1, r1, x2, y2, r2;

    printf("_______Test Case 1_______\n");
    x1 = 0; y1 = 0; r1 = 1;
    x2 = 4; y2 = 3; r2 = 0.5;

    do_they_intersect(x1, y1, r1, x2, y2, r2);

    printf("_______Test Case 1_______\n");
    x1 = 0; y1 = 0; r1 = 7;
    x2 = 4; y2 = 3; r2 = 1.9;

    do_they_intersect(x1, y1, r1, x2, y2, r2);

    printf("_______Test Case 1_______\n");
    x1 = 0; y1 = 0; r1 = 3;
    x2 = 4; y2 = 3; r2 = 3;

    do_they_intersect(x1, y1, r1, x2, y2, r2);



}

double d(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void do_they_intersect(double x1, double y1, double r1, double x2, double y2, double r2)
{
    printf("Point 1: (%lf, %lf) R = %lf\n", x1, y1, r1);
    printf("Point 2: (%lf, %lf) R = %lf\n", x2, y2, r2);

    double d_ = d(x1, y1, x2, y2);

    if (d_ > r1 + r2)
    {
        printf("No, circles is too far\n");
    }
    else if (d_ < fabs(r1 - r2))
    {
        printf("No, smaller circle completely in the larger circle\n");
    }
    else printf("Yes, they intersect\n");
}