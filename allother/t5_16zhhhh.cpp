#include <stdio.h>
#include <math.h>

/**
 * Task 'zh' (pls, don't use cyrillic symbol for sub-task names): Approximate calculation of the sum of terms where |term| >= epsilon.
 * Function: y = ln((1+x)/(1-x)) = 2 * (x + x^3/3 + x^5/5 + ...)
 * Condition: |x| < 1
 */
void solve_zh() {
    // --- Hardcoded variables (Input) ---
    double x = 0.5;         // Argument (|x| must be < 1)
    double epsilon = 0.0001; // Precision threshold

    // --- Validation ---
    if (fabs(x) >= 1.0) {
        printf("Error: |x| must be less than 1.\n");
        return;
    }

    // --- Calculation ---
    double sum = 0.0;
    int k = 1;              // The power/denominator index (1, 3, 5...)
    double term;

    printf("Calculating series for x=%.2f, epsilon=%.5f\n", x, epsilon);

    do {
        // Calculate current term: 2 * (x^k / k)
        // Note: pow(x, k) can be slow, but it's clear for the formula.
        // Optimized way would be multiplying by x*x each step.
        term = 2.0 * pow(x, k) / k;

        // Check condition: if absolute value is >= epsilon, add to sum
        if (fabs(term) >= epsilon) {
            sum += term;
            // Print intermediate step (optional, for verification)
            // printf("k=%d, term=%.6f, sum=%.6f\n", k, term, sum);
        } else {
            // Since terms decrease for |x| < 1, we can stop early
            break;
        }

        k += 2; // Move to next odd number (1 -> 3 -> 5)
    } while (1);

    // --- Output ---
    printf("-------------------------\n");
    printf("Approximate Sum = %f\n", sum);

    // Comparison with actual math function log((1+x)/(1-x))
    double actual = log((1 + x) / (1 - x));
    printf("Math library value: %f\n", actual);
}