#include <stdio.h>

/**
 * Helper function to print a number in binary (for visualization)
 */
void print_binary(unsigned int num) {
    for (int k = 31; k >= 0; k--) {
        printf("%d", (num >> k) & 1);
        if (k % 4 == 0) printf(" ");
    }
    printf("\n");
}

/**
 * Task 6.12: Swap bits at positions i and j in number m.
 */
void t6_12() {
    // Hardcoded variables (Input)
    // m: Natural number to process
    unsigned int m = 29; // Binary: ...0001 1101
    // i, j: Bit positions to swap (0-indexed)
    int i = 1; // Bit at pos 1 is '0' in 29
    int j = 3; // Bit at pos 3 is '1' in 29

    printf("Original m = %u (0x%X)\n", m, m);
    printf("Binary: ");
    print_binary(m);
    printf("Swapping bits at pos %d and %d...\n", i, j);

    // Calculation
    // 1. Extract the values of the bits at positions i and j
    unsigned int bit_i = (m >> i) & 1;
    unsigned int bit_j = (m >> j) & 1;

    // 2. Only perform swap if bits are different.
    // If they are the same (both 0 or both 1), swapping changes nothing.
    if (bit_i != bit_j) {
        // We can flip both bits using XOR to swap them.
        // Create a mask with 1s at position i and j: (1 << i) | (1 << j)
        unsigned int mask = (1 << i) | (1 << j);
        
        // XOR the original number with the mask.
        // 0 ^ 1 = 1 (flips 0 to 1)
        // 1 ^ 1 = 0 (flips 1 to 0)
        m = m ^ mask;
    }

    // --- Output ---
    printf("-------------------------\n");
    printf("Result m = %u\n", m);
    printf("Hex format: 0x%X\n", m);
    printf("Binary: ");
    print_binary(m);
}