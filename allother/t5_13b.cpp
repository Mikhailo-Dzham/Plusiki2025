#include <stdio.h>
#include <math.h>

/**
 * Task 5.13b: Calculate product P = Product(a[k] * b[k]) for k=1 to n.
 * Recurrence relations:
 * a[1] = 1, b[1] = 1
 * a[k] = sqrt(b[k-1] + a[k-1]) / 5
 * b[k] = 2*b[k-1] + 5*a[k-1]^2
 */
void t4_13b() {
    // Hardcoded variables (Input)
    int n = 5; // Number of multiplications

    // Calculation
    double product = 1.0;

    // Previous values (initially for k=1)
    double a_prev = 1.0;
    double b_prev = 1.0;

    // Variables for current step
    double a_curr, b_curr;

    printf("Calculating product for n=%d...\n", n);

    for (int k = 1; k <= n; k++) {
        if (k == 1) {
            // Base case
            a_curr = a_prev;
            b_curr = b_prev;
        } else {
            // Recursive step for k >= 2
            // Calculate a[k] using previous values
            a_curr = sqrt(b_prev + a_prev) / 5.0;

            // Calculate b[k] using previous values
            b_curr = 2 * b_prev + 5 * (a_prev * a_prev);

            // Update history for next iteration
            a_prev = a_curr;
            b_prev = b_curr;
        }

        // Multiply into total product
        product *= (a_curr * b_curr);

        printf("k=%d: a=%.4f, b=%.4f, current P=%.4f\n", k, a_curr, b_curr, product);
    }

    // --- Output ---
    printf("-------------------------\n");
    printf("Final Product P = %f\n", product);
}