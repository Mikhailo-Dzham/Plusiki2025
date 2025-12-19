#include <stdio.h>

/**
 * Function to check for matching bits (logical AND intersection).
 * Prints the positions where both numbers have a '1'.
 */
void check_common_bits(unsigned int n1, unsigned int n2) {
    int found_common = 0;

    printf("Checking numbers: %u and %u\n", n1, n2);

    // Iterate through all 32 bits of an integer
    // sizeof(int) usually is 4 bytes -> 32 bits
    for (int k = 0; k < 32; k++) {
        // Extract bit at position k for both numbers
        int bit1 = (n1 >> k) & 1;
        int bit2 = (n2 >> k) & 1;

        // Check if both bits are 1 (Common set bit)
        if (bit1 == 1 && bit2 == 1) {
            printf(" -> Common bit (1) found at position: %d\n", k);
            found_common = 1;
        }
    }

    if (!found_common) {
        printf("Result: The numbers do NOT have common set bits.\n");
    } else {
        printf("Result: The numbers HAVE common set bits at the positions listed above.\n");
    }
}

void t6_27() {
    // Hardcoded variables (Input)
    unsigned int number_a = 13; // Binary: 0000 1101
    unsigned int number_b = 6;  // Binary: 0000 0110
    // Overlap expected at bit 2 (value 4)

    // Execution
    check_common_bits(number_a, number_b);
}