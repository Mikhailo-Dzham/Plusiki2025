#include <stdio.h>
#include <stdlib.h>

// Helper function to create the input file for demonstration
void create_input_file(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;
    // Data: 3 positives, 3 negatives
    fprintf(f, "10 -5 20 -8 30 -1"); 
    fclose(f);
}

// Main logic function required by prompt
int t11_9a() {
    const char *file_f = "F.txt";
    const char *file_h = "H.txt";
    const char *file_g = "G.txt";

    // 1. Generate data (hardcoded for testing)
    create_input_file(file_f);

    FILE *f, *h, *g;
    int num, pos_count = 0, neg_count = 0;

    // 2. Count positives and negatives
    f = fopen(file_f, "r");
    if (!f) { perror("Error opening F"); return 1; }

    while (fscanf(f, "%d", &num) == 1) {
        if (num > 0) pos_count++;
        else if (num < 0) neg_count++;
    }
    fclose(f);

    // 3. Check condition
    if (pos_count != neg_count) {
        printf("Error: File does not contain equal number of positive and negative numbers.\n");
        return 0; // Do nothing else
    }

    printf("Counts are equal (%d). Processing files...\n", pos_count);

    // 4. Pass 1: Write all positives to auxiliary file H
    f = fopen(file_f, "r");
    h = fopen(file_h, "w");
    
    while (fscanf(f, "%d", &num) == 1) {
        if (num > 0) {
            fprintf(h, "%d ", num);
        }
    }
    fclose(f);
    fclose(h);

    // 5. Pass 2: Merge Negatives from F and Positives from H into G
    f = fopen(file_f, "r");
    h = fopen(file_h, "r");
    g = fopen(file_g, "w");

    int h_val;
    while (fscanf(f, "%d", &num) == 1) {
        if (num < 0) {
            // Write the negative number from F
            fprintf(g, "%d ", num);
            
            // Read next positive number from H and write it
            if (fscanf(h, "%d", &h_val) == 1) {
                fprintf(g, "%d ", h_val);
            }
        }
    }

    printf("Done. Result written to %s\n", file_g);

    fclose(f);
    fclose(h);
    fclose(g);

    return 0;
}