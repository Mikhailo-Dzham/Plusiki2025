#include <stdio.h>
#include <math.h> //for sqrt()

void solution_logic_with_t(double a, double b, double c);
double discriminator(double a, double b, double c);
double root (double a, double b, double d);
void solution_from_t(double t);


// Main function of the task
void t3_7b()
{
    printf("\n_______Task 3-7b_______\n");

    // ax**4 + bx**2 + c = 0

    // Test Cases

    // Initial coefficients (Test 1: Complex roots)
    printf("Test 1 (a=1, b=3, c=4):\n");
    solution_logic_with_t(1, 3, 4);

    // Test 2: Two real roots (a=1, b=-3, c=2 -> roots are 1, 2)
    printf("\nTest 2 (a=1, b=-3, c=2):\n");
    solution_logic_with_t(1, -3, 2);

    // Test 3: One real root (a=1, b=2, c=1 -> root is -1)
    printf("\nTest 3 (a=1, b=2, c=1):\n");
    solution_logic_with_t(1, 2, 1);
}

//Updatet for ax**4 + bx**2 + c = 0
void solution_logic_with_t(double a, double b, double c)
{
    //Discriminator
    printf("\nFind discriminator:");
    double dis = discriminator(a, b, c);
    printf("%lf\n", dis);

    if (dis < 0.0) // Check if the roots are complex
    {
        printf("\nRoots is complex\n");
    } else // Then we can continue the solution
    {
        double sqrt_d = sqrt(dis); // Square root of the discriminant

        if (not dis) //dis == 0, One solution, or identical ones
        {
            double t = root (a, b, sqrt_d);
            printf("t = %lf\n", t);
            printf("Roots:");
            solution_from_t(t);
        } else // Two solutions
        {
            double t1 = root (a, b, sqrt_d), t2 = root (a, b, -sqrt_d);
            printf("t1 = %lf\n t2 = %lf\n", t1, t2);
            printf("Roots:");
            solution_from_t(t1);
            solution_from_t(t2);
        }
    }
}

// roots from t
void solution_from_t(double t)
{
    if (t < 0)
    {
        printf("\nRoots is complex");
    } else
    {
        printf("%lf %lf ", sqrt(t), -sqrt(t));
    }
}