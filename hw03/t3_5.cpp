#include <stdio.h>

int max(int n1, int n2);

void t3_5()
{
    printf("\n_______Task 3-5_______\n");

    int a, b;
    printf("a b:");
    scanf("%d %d", &a, &b); //The view of input is not specified in the task

    printf("%d", max(a, b));

}

int max(int n1, int n2)
{
    if (n1 > n2) { return n1;} else {return n2;}
}