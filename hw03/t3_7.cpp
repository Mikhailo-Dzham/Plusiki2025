#include <stdio.h>
#include <math.h>

void solution_logic(double a, double b, double c);
double discriminator(double a, double b, double c);
double root (double a, double b, double d);


// Main function of the task
void t3_7a()
{
printf("\n_______Task 3-7_______\n");

// ax**2 + bx + c = 0

//Input coefficients
//a cannot be 0
double a = 1, b = 3, c = 4;

//Solution
solution_logic(a, b, c);

}

void solution_logic(double a, double b, double c)
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

printf("Roots:");
if (not dis) //dis == 0, One solution, or identical ones
{
    printf("%lf", root (a, b, sqrt_d));
} else // Two solutions
{
    printf("%lf %lf", root (a, b, sqrt_d), root (a, b, -sqrt_d));
}
}
}


// Function to find the discriminant, returns the discriminant
double discriminator(double a, double b, double c)
{
return b * b - 4 * a * c;
}

// Formula for finding roots, d is already the square root of the discriminant
// with the corresponding sign. returns one root
double root (double a, double b, double d)
{
return (-b + d) / (2 *a);
}