#include <stdio.h>
#include <string.h>

/**
 * Define the structure for Address (City, Street, House, Apartment)
 */
typedef struct {
    char city[50];
    char street[50];
    int house_number;
    int apartment_number;
} Address;

/**
 * Function to initialize (simulate input) an address structure.
 * In a real scenario, this would use scanf/fgets.
 */
Address create_address(const char* city, const char* street, int house, int apt) {
    Address new_addr;
    // Copy strings safely
    strncpy(new_addr.city, city, sizeof(new_addr.city) - 1);
    strncpy(new_addr.street, street, sizeof(new_addr.street) - 1);
    // Ensure null-termination
    new_addr.city[49] = '\0';
    new_addr.street[49] = '\0';
    
    new_addr.house_number = house;
    new_addr.apartment_number = apt;
    return new_addr;
}

/**
 * Function to display (output) the address structure.
 */
void print_address(const Address* addr) {
    printf("--- Address Info ---\n");
    printf("City:      %s\n", addr->city);
    printf("Street:    %s\n", addr->street);
    printf("House:     %d\n", addr->house_number);
    printf("Apartment: %d\n", addr->apartment_number);
    printf("--------------------\n");
}

/**
 * Main function to demonstrate the functionality (Hardcoded logic)
 */
void t10_6g() {
    // Simulate input data
    Address my_addr = create_address("Kyiv", "Khreshchatyk", 25, 101);
    Address work_addr = create_address("Lviv", "Svobody Ave", 10, 5);

    // Output the data
    print_address(&my_addr);
    print_address(&work_addr);
}