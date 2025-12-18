#include <stdio.h>
#include <math.h>
#include <float.h> // For DBL_MAX

// Function declarations
void erelu_solution_logic(double a, double x);
double calculate_erelu(double a, double x);
double calculate_derivative(double a, double x);


// Main function of the task (and test cases)
void t3_23g()
{
    printf("\n_______Task 3-23g_______\n");

    // Input parameters
    // a - scaling factor, x - input value
    double a = 2.0;

    // Case 1: x < 0
    double x1 = -1.5;
    printf("\nTest Case 1 (x < 0)\n");
    erelu_solution_logic(a, x1);

    // Case 2: x >= 0
    double x2 = 3.0;
    printf("\nTest Case 2 (x >= 0)\n");
    erelu_solution_logic(a, x2);
}

void erelu_solution_logic(double a, double x)
{
    printf("Input: a = %.2lf, x = %.2lf\n", a, x);

    // Calculate Function Value
    double result = calculate_erelu(a, x);
    printf("eReLu(a, x) = %lf\n", result);

    // Calculate Derivative
    double deriv = calculate_derivative(a, x);

    // Check for explicit "infinity" request (though unlikely for this specific function)
    if (deriv == DBL_MAX) {
        printf("Derivative  = Infinity (DBL_MAX)\n");
    } else {
        printf("Derivative  = %lf\n", deriv);
    }
}

// Function to calculate eReLu value based on the piecewise formula
double calculate_erelu(double a, double x)
{
    if (x < 0)
    {
        return a * (exp(x) - 1);
    }
    else // x >= 0
    {
        return 0.0;
    }
}

// Function to calculate the derivative
// Treats infinity as DBL_MAX per requirements
double calculate_derivative(double a, double x)
{
    double result;

    if (x < 0)
    {
        result = a * exp(x);
    }
    else // x >= 0
    {
        result = 0.0;
    }

    // Checking for infinity logic as requested
    // (Although a*e^x is finite for finite x, strict safety check below)
    if (isinf(result))
    {
        return DBL_MAX;
    }

    return result;
}