#include <stdio.h>
#include <stdlib.h>

/**
 * Function to free the memory of a dynamic matrix
 */
void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * Function to print the matrix
 */
void print_matrix(double** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        printf("Matrix is empty.\n");
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Task 9.9k: Create dynamic matrix NxM, fill with input, delete column k.
 */
void t9_9k() {
    int N, M;

    // --- 1. Input dimensions ---
    printf("Enter number of rows (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input for rows.\n");
        return;
    }

    printf("Enter number of columns (M): ");
    if (scanf("%d", &M) != 1 || M <= 0) {
        printf("Invalid input for columns.\n");
        return;
    }

    // --- 2. Allocate memory ---
    // Allocate array of pointers (rows)
    double** matrix = (double**)malloc(N * sizeof(double*));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return;
    }

    // Allocate memory for each row
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(M * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i);
            // Free previously allocated rows
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return;
        }
    }

    // --- 3. Fill matrix ---
    printf("Enter elements of the matrix (%d x %d):\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // --- 4. Show original matrix ---
    printf("\n--- Original Matrix ---\n");
    print_matrix(matrix, N, M);

    // --- 5. Delete column k ---
    int k;
    printf("\nEnter the column index to delete (0 to %d): ", M - 1);
    if (scanf("%d", &k) != 1) {
        printf("Invalid input for index.\n");
        free_matrix(matrix, N);
        return;
    }

    if (k < 0 || k >= M) {
        printf("Error: Column index %d is out of bounds.\n", k);
    } else {
        printf("Deleting column %d...\n", k);

        // Logic: Shift elements left, then reallocate to shrink
        if (M == 1) {
            // Special case: deleting the only column makes the matrix empty
            for (int i = 0; i < N; i++) {
                free(matrix[i]);
                matrix[i] = NULL;
            }
            M = 0;
        } else {
            for (int i = 0; i < N; i++) {
                // Shift elements to the left starting from k
                for (int j = k; j < M - 1; j++) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                
                // Reallocate memory for the row (shrink by 1 double)
                double* temp = (double*)realloc(matrix[i], (M - 1) * sizeof(double));
                if (temp != NULL) {
                    matrix[i] = temp;
                } else {
                    printf("Warning: Realloc failed for row %d, memory unchanged but logic considers it smaller.\n", i);
                }
            }
            M--; // Update column count
        }

        // --- 6. Show result ---
        printf("\n--- Updated Matrix ---\n");
        print_matrix(matrix, N, M);
    }

    // --- 7. Clean up ---
    if (M > 0) {
        free_matrix(matrix, N);
    } else {
        free(matrix); // Only the row pointers array remains if M was 0
    }
}