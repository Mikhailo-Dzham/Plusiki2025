#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int min_age;
    int max_age;
} Toy;

// Helper to create binary data
void create_toy_file(const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;

    Toy toys[] = {
        {"Doll", 150.0, 3, 6},
        {"Constructor", 500.0, 2, 12}, // This matches criteria if Y=500
        {"Ball", 100.0, 2, 12},
        {"Constructor", 1200.0, 10, 16}
    };

    fwrite(toys, sizeof(Toy), 4, f);
    fclose(f);
}

// Main logic function required by prompt
int t11_12ye() {
    const char *input_file = "toys.bin";
    const char *output_file = "results.bin";
    float target_price_Y = 500.0; // Hardcoded search price Y

    // 1. Generate data
    create_toy_file(input_file);

    FILE *f_in = fopen(input_file, "rb");
    FILE *f_out = fopen(output_file, "wb");
    
    if (!f_in || !f_out) { perror("File error"); return 1; }

    Toy t;
    int found = 0;

    printf("Searching for 'Constructor', Price: %.2f, Age: 2-12...\n", target_price_Y);

    while (fread(&t, sizeof(Toy), 1, f_in)) {
        // Criteria: Name "Constructor", Price == Y, Age 2 to 12
        // Note: Using "Constructor" as translation for "конструктор"
        if (strcmp(t.name, "Constructor") == 0 && 
            t.price == target_price_Y && 
            t.min_age == 2 && 
            t.max_age == 12) {
            
            // Write to console
            printf("Found: %s, Price: %.2f, Age: %d-%d\n", 
                   t.name, t.price, t.min_age, t.max_age);
            
            // Write to binary file
            fwrite(&t, sizeof(Toy), 1, f_out);
            found = 1;
        }
    }

    if (!found) {
        printf("No suitable toy found.\n");
        // Write a specific record indicating absence
        Toy absence_msg = {"NOT FOUND", 0.0, 0, 0};
        fwrite(&absence_msg, sizeof(Toy), 1, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}