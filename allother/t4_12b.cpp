#include <stdio.h>


 // Formula: y = x^(3^n) + ... + x^9 + x^3 + 1

void t4_12b() {
    // Hardcoded variables (Input)
    int n = 4;   // The power limit parameter
    double x = 1.5; // The base value

    double sum = 1.0;    // Initialize sum with the constant term '1'
    
    // The first term is x^3. 
    // We calculate it manually: x * x * x
    double current_term = x * x * x;

    // Loop n times to add terms: x^3, x^9, x^27...
    for (int i = 0; i < n; i++) {
        sum += current_term;
        
        // Prepare the next term.
        // Since the powers are 3, 9, 27 (powers of 3),
        // the next term is the cube of the current term.
        // term(k+1) = (term(k))^3
        current_term = current_term * current_term * current_term;
    }

    // Output
    printf("Task 12b Result:\n");
    printf("n = %d, x = %.2f\n", n, x);
    printf("y = %f\n", sum);
}