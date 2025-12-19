#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9 // Threshold for zero comparison in floating point arithmetic

/**
 * 1. Allocates memory for an N x M integer matrix.
 */
int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Clean up previous rows if one fails
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

/**
 * 2. Frees the memory of the matrix.
 */
void free_matrix(int** matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * Helper: Print matrix
 */
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

/**
 * 3. Calculate Determinant (Recursive).
 * Note: Only for square matrices.
 */
long long calculate_determinant(int** matrix, int n) {
    // Base case: 1x1 matrix
    if (n == 1) {
        return matrix[0][0];
    }
    // Base case: 2x2 matrix (optimization)
    if (n == 2) {
        return (long long)matrix[0][0] * matrix[1][1] - (long long)matrix[0][1] * matrix[1][0];
    }

    long long det = 0;
    int sign = 1;

    // Allocate minor matrix (n-1) x (n-1)
    int** submatrix = allocate_matrix(n - 1, n - 1);
    if (submatrix == NULL) {
        printf("Memory allocation error during determinant calculation.\n");
        exit(1);
    }

    // Laplace expansion along the first row
    for (int x = 0; x < n; x++) {
        // Construct submatrix by removing row 0 and column x
        int sub_i = 0;
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix[sub_i][sub_j] = matrix[i][j];
                sub_j++;
            }
            sub_i++;
        }

        // Recursive call
        det += sign * matrix[0][x] * calculate_determinant(submatrix, n - 1);
        sign = -sign;
    }

    free_matrix(submatrix, n - 1);
    return det;
}

/**
 * 4. Calculate Rank using Gaussian Elimination.
 * Uses double precision to handle divisions correctly.
 */
int calculate_rank(int** matrix, int rows, int cols) {
    // Create a copy in double for calculation to avoid destroying original integer matrix
    double** temp_mat = (double**)malloc(rows * sizeof(double*));
    for(int i=0; i<rows; i++) {
        temp_mat[i] = (double*)malloc(cols * sizeof(double));
        for(int j=0; j<cols; j++) {
            temp_mat[i][j] = (double)matrix[i][j];
        }
    }

    int rank = 0;
    int pivot_row = 0;
    
    // Iterate through columns
    for (int j = 0; j < cols && pivot_row < rows; j++) {
        // Find pivot in current column j, starting from pivot_row
        int sel = pivot_row;
        while (sel < rows && fabs(temp_mat[sel][j]) < EPSILON) {
            sel++;
        }

        if (sel == rows) {
            // No non-zero pivot in this column, move to next column
            continue;
        }

        // Swap rows if necessary
        if (sel != pivot_row) {
            double* tmp = temp_mat[sel];
            temp_mat[sel] = temp_mat[pivot_row];
            temp_mat[pivot_row] = tmp;
        }

        // Eliminate rows below
        for (int i = pivot_row + 1; i < rows; i++) {
            if (fabs(temp_mat[i][j]) > EPSILON) {
                double factor = temp_mat[i][j] / temp_mat[pivot_row][j];
                for (int k = j; k < cols; k++) {
                    temp_mat[i][k] -= factor * temp_mat[pivot_row][k];
                }
            }
        }
        
        pivot_row++;
        rank++;
    }

    // Free temp matrix
    for(int i=0; i<rows; i++) free(temp_mat[i]);
    free(temp_mat);

    return rank;
}

/**
 * Main Task Logic
 */
void t9_5() {
    // --- Hardcoded Data Configuration ---
    int rows = 3;
    int cols = 3; 
    
    // We allocate dynamically as per task requirement
    int** matrix = allocate_matrix(rows, cols);

    // Hardcoding values:
    // Example:
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // Determinant should be 0, Rank should be 2.
    
    int values[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Filling the dynamic matrix
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = values[i][j];
        }
    }

    // --- Output & Calculations ---
    printf("--- Task 5: Dynamic Matrix Operations ---\n");
    printf("Matrix (%dx%d):\n", rows, cols);
    print_matrix(matrix, rows, cols);
    printf("-----------------------------------------\n");

    // 1. Calculate Determinant
    if (rows == cols) {
        long long det = calculate_determinant(matrix, rows);
        printf("Determinant: %lld\n", det);
    } else {
        printf("Determinant: Not applicable (Matrix is not square)\n");
    }

    // 2. Calculate Rank
    int rk = calculate_rank(matrix, rows, cols);
    printf("Rank:        %d\n", rk);

    // --- Clean up ---
    free_matrix(matrix, rows);
    printf("Memory successfully freed.\n");
}