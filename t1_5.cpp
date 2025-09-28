#include <stdio.h>

void t1_5()
{
    printf("\n_______Task 1-5_______\n");

    double a;
    printf("Enter a double number to continue\n x=");
    scanf("%lf",&a);

    //b
    double x=a, x2 = x * x; // 1/3
    printf("b) x**6 = %lf\n", x2 * x2 * x2); // 3/3

    double y=a, y3 = y * y * y, y6 = y3 * y3; // 3/5
    printf("b) x**15 = %lf\n", y6 * y6 * y3 ); // 5/5

    double z=a, z2 = z * z, z4 = z2*z2, z8= z4 *z4, z16= z8*z8, z32 =z16 * z16, z64 = z32 * z32; // 6/6
    printf("b) x**64 = %lf\n", z64);

}