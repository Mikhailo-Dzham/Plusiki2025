#include <stdio.h>
//2+31; 45*54-11; 15/4; 15.0/4; 67%5; (2*45.1 +3.2)/2;

void t1_1() {
    printf("\n_______Task 1-1_______\n");

    int a1 = 2, b1 = 31;
    int res1 = a1 + b1;
    printf("2+31; result 1:  %d\n", res1);

    int a2 = 45, b2 = 54, c2 = 11;
    int res2 = a2 * b2 -c2;
    printf("45*54-11; result 2: %d\n", res2);

    int a3=15, b3 = 4;
    int res3 = a3 / b3;
    printf("15/4; result 3: %d\n", res3);

    float a4=15.0, b4=4;
    printf("15.0/4; result 4: %f\n", (a4/b4));

    int a5=67, b5=5;
    printf("67%%5; result 5: %d\n", (a5 % b5));

    printf("(2*45.1 +3.2)/2; result 6: %f\n", ((2 * 45.1 + 3.2)/2));
}