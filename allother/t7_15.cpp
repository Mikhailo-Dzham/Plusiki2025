#include <stdio.h>
#include <stdlib.h> // for abs()

/**
 * Task 7.15: Find the digit that appears most frequently in an integer.
 * If there are multiple, print the largest one.
 */
void t7_15() {
    // --- Hardcoded Input ---
    // Using long long to handle larger numbers
    long long number = 1415926535;
    
    printf("Task 15: Analyzing number %lld\n", number);

    // Logic
    // Array to store frequency of digits 0-9. Index = digit.
    int counts[10] = {0}; 
    
    // Work with absolute value to handle negative numbers
    long long temp = llabs(number);

    // Edge case: if number is 0
    if (temp == 0) {
        counts[0] = 1;
    }

    // Parse digits
    while (temp > 0) {
        int digit = temp % 10;
        counts[digit]++;
        temp /= 10;
    }

    // Find the max frequency
    int max_frequency = -1;
    int result_digit = -1;

    // Iterate from 9 down to 0 to automatically satisfy "print the largest digit"
    // if frequencies are equal.
    for (int d = 9; d >= 0; d--) {
        if (counts[d] > max_frequency) {
            max_frequency = counts[d];
            result_digit = d;
        }
    }

    // --- Output ---
    printf("Frequencies array (Index=Digit, Value=Count):\n");
    for(int i=0; i<10; i++) {
        if(counts[i] > 0) printf("[%d]: %d times\n", i, counts[i]);
    }
    printf("-------------------------\n");
    printf("Digit with max frequency: %d (appears %d times)\n", result_digit, max_frequency);
}