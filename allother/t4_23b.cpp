#include <stdio.h>
#include <math.h>   // For fabs() function
#include <float.h>  // For DBL_MAX

void t4_23b() {
    // Hardcoded variables (Input)
    // 'n' is the number of elements
    int n = 5; 
    // Array of real numbers y1...yn
    double y[] = {0.5, -3.2, 4.0, -0.8, 1.5};

    // Calculation
    double min_abs_z = DBL_MAX; // Initialize with the largest possible double value

    printf("Processing values:\n");

    for (int i = 0; i < n; i++) {
        double current_y = y[i];
        double abs_y = fabs(current_y); // Calculate absolute value of y
        double abs_z; 

        // Apply the logic from the task condition (part b)
        // If |y| >= 1, then z = y (so |z| = |y|)
        // If |y| < 1,  then z = 2 (so |z| = 2)
        if (abs_y >= 1.0) {
            abs_z = abs_y;
        } else {
            abs_z = 2.0;
        }

        // Check if we found a new minimum
        if (abs_z < min_abs_z) {
            min_abs_z = abs_z;
        }

        // Optional: print intermediate steps for clarity
        printf("y[%d] = %.2f -> |z| = %.2f\n", i, current_y, abs_z);
    }

    // Output
    printf("\nResult min(|z|) = %.2f\n", min_abs_z);
}