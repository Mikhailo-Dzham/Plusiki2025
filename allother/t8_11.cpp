#include <stdio.h>

#define N 7 // Matrix size (must be odd for a perfect center start, matching the image)

/**
 * Task 8.11: Fill an N x N matrix with numbers 1..N^2 in a spiral outward from the center.
 * Directions: Right -> Up -> Left -> Down -> ...
 */
void t8_11() {
    int matrix[N][N] = {0}; // Initialize with 0
    
    // --- Starting Point (Center) ---
    int r = N / 2;
    int c = N / 2;
    
    int current_num = 1;
    matrix[r][c] = current_num; // Place 1 at the center
    current_num++;

    // --- Spiral Logic ---
    int step_length = 1; // Initial movement length
    
    // We loop until we have filled all numbers up to N*N
    while (current_num <= N * N) {
        // 1. Move RIGHT 'step_length' times
        for (int i = 0; i < step_length; i++) {
            c++; // Move right
            if (c < N && c >= 0 && r < N && r >= 0) { // Boundary check
                matrix[r][c] = current_num++;
            }
        }
        if (current_num > N * N) break;

        // 2. Move UP 'step_length' times
        for (int i = 0; i < step_length; i++) {
            r--; // Move up
            if (c < N && c >= 0 && r < N && r >= 0) {
                matrix[r][c] = current_num++;
            }
        }
        if (current_num > N * N) break;

        // Increase step length after Right & Up
        step_length++;

        // 3. Move LEFT 'step_length' times
        for (int i = 0; i < step_length; i++) {
            c--; // Move left
            if (c < N && c >= 0 && r < N && r >= 0) {
                matrix[r][c] = current_num++;
            }
        }
        if (current_num > N * N) break;

        // 4. Move DOWN 'step_length' times
        for (int i = 0; i < step_length; i++) {
            r++; // Move down
            if (c < N && c >= 0 && r < N && r >= 0) {
                matrix[r][c] = current_num++;
            }
        }
        // Increase step length after Left & Down
        step_length++;
    }

    // --- Output ---
    printf("Task 11: Spiral Matrix (%dx%d)\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}