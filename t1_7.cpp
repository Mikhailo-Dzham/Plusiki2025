#include <stdio.h>
#include <math.h>

void t1_7()
{
    printf("\n_______Task 1-7______\n");

    double a;
    printf("Enter a number to continue\n x=");
    scanf("%lf",&a);

    //no math
    long intPart_noMath;
    double floatPart_noMath;
    intPart_noMath = (long)a;
    floatPart_noMath = a - intPart_noMath;

    //math
    double intPart_math;
    double floatPart_math = modf(a, &intPart_math);

    printf("intPart without Math = %li\n",intPart_noMath);
    printf("intPart with Math = %.0f\n", intPart_math);
    printf("floatPart without Math = %.6f\n",floatPart_noMath);
    printf("floatPart with Math = %.6f\n", floatPart_math);

    //
    printf("Smallest > x=%.0f\n", ceil(a));
    printf("Biggest <x=%.0f\n", floor(a));
    printf("Round x = %.0f\n", round(a));
}
