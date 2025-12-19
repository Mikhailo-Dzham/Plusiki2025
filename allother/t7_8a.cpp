#include <stdio.h>
#include <math.h>

/**
 * Helper function: Check if a number is prime.
 * Returns 1 if prime, 0 otherwise.
 */
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/**
 * Task 8a: Count numbers in an array that are perfect squares of prime numbers.
 */
void t7_8a() {
    // --- Hardcoded Input ---
    // Array of size N
    int arr[] = {4, 9, 16, 25, 49, 100, 12, 121, 3}; 
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Task 8a: Processing array of size %d\n", N);
    printf("Array elements: ");
    for(int i=0; i<N; i++) printf("%d ", arr[i]);
    printf("\n");

    // --- Logic ---
    int count = 0;

    for (int i = 0; i < N; i++) {
        int val = arr[i];
        
        // 1. Check if number is a perfect square
        // We take the integer square root
        int root = (int)round(sqrt(val));
        
        // If root * root == val, then it's a perfect square
        if (root * root == val) {
            // 2. Check if the root itself is a prime number
            // e.g., if val=16, root=4. 4 is not prime -> skip.
            // e.g., if val=49, root=7. 7 is prime -> count it.
            if (is_prime(root)) {
                printf(" -> Found match: %d is %d^2 (and %d is prime)\n", val, root, root);
                count++;
            }
        }
    }

    // --- Output ---
    printf("-------------------------\n");
    printf("Total count of such numbers: %d\n", count);
}