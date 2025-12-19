#include <stdio.h>
#include <string.h>

/**
 * Date structure used within Employee struct
 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 * Employee structure
 */
typedef struct {
    char surname[50];
    char name[50];
    char gender;        // 'M' for Male, 'F' for Female
    Date birth_date;
    char position[50];  // Added to satisfy sub-task (a)
} Employee;

/**
 * Sub-task A: Find the position held by the largest number of employees.
 */
void find_most_frequent_position(Employee employees[], int n) {
    int max_count = 0;
    char best_position[50] = "";

    // Iterate through each employee to count their position frequency
    for (int i = 0; i < n; i++) {
        int current_count = 0;
        // Compare with all other employees
        for (int j = 0; j < n; j++) {
            if (strcmp(employees[i].position, employees[j].position) == 0) {
                current_count++;
            }
        }

        if (current_count > max_count) {
            max_count = current_count;
            strcpy(best_position, employees[i].position);
        }
    }

    printf("\n[Sub-task A] Most frequent position:\n");
    printf("Position: '%s' (Count: %d)\n", best_position, max_count);
}

/**
 * Sub-task B: Find employees with the same names (First Name).
 */
void find_same_names(Employee employees[], int n) {
    printf("\n[Sub-task B] Employees with the same names:\n");
    int found_any = 0;

    // Use a simple O(N^2) check. 
    // To avoid printing duplicates (A==B and B==A), we print only when j > i.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(employees[i].name, employees[j].name) == 0) {
                printf("Match found: %s %s and %s %s (Name: %s)\n",
                       employees[i].name, employees[i].surname,
                       employees[j].name, employees[j].surname,
                       employees[i].name);
                found_any = 1;
            }
        }
    }

    if (!found_any) {
        printf("No employees with identical names found.\n");
    }
}

/**
 * Sub-task C: Find employees whose surname starts with a specific letter.
 */
void find_by_surname_initial(Employee employees[], int n, char letter) {
    printf("\n[Sub-task C] Employees with surname starting with '%c':\n", letter);
    int found_count = 0;

    for (int i = 0; i < n; i++) {
        // Check first character of surname (case-sensitive here)
        if (employees[i].surname[0] == letter) {
            printf("- %s %s (Position: %s)\n", 
                   employees[i].surname, employees[i].name, employees[i].position);
            found_count++;
        }
    }

    if (found_count == 0) {
        printf("No employees found starting with '%c'.\n", letter);
    }
}

/**
 * Main function to solve Task 13
 */
void t10_13abv() {
    // --- Hardcoded Data Input ---
    // Array of 5 employees
    Employee staff[] = {
        {"Ivanov", "Ivan", 'M', {15, 5, 1990}, "Manager"},
        {"Petrenko", "Maria", 'F', {20, 10, 1992}, "Accountant"},
        {"Shevchenko", "Taras", 'M', {9, 3, 1814}, "Artist"},
        {"Sidorov", "Ivan", 'M', {1, 1, 1995}, "Manager"}, // Same name as [0], same position as [0]
        {"Ivanchuk", "Olga", 'F', {12, 12, 1998}, "Developer"}
    };
    int n = sizeof(staff) / sizeof(staff[0]);
    char target_letter = 'I'; // Looking for surnames starting with 'I'

    printf("--- Task 13: Employee Analysis (N=%d) ---\n", n);

    // 1. Find most popular position
    find_most_frequent_position(staff, n);

    // 2. Find employees with same names
    find_same_names(staff, n);

    // 3. Find by surname letter
    find_by_surname_initial(staff, n, target_letter);
}