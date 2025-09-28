#include  <stdio.h>
#include  <math.h>

void t1_2() {
    printf("\n_______Task 1-2_______\n");
    float n1 = 0.0001;
    float n2 = 24.33E5;
    long double n3 = M_PI;
    double n4 = exp(1);
    long double n5 = sqrt(5);
    double n6 = log(100);

    printf("n1:  %.2f\n", n1);
    printf("n2:  %.2f\n", n2);
    printf("n3: %.2Lf\n", n3);
    printf("n4: %.2f\n", n4);
    printf("n5: %.2Lf\n", n5);
    printf("n6: %.2lf\n", n6);
}