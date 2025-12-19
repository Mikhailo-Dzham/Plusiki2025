#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Auto {
public:
    string name;
    string model;
    string number;
    int ownerId;

    Auto(string n, string m, string num, int id) 
        : name(n), model(m), number(num), ownerId(id) {}

    // Overload operator for easy printing
    friend ostream& operator<<(ostream& os, const Auto& car) {
        os << "[" << car.name << " " << car.model 
           << " | Plate: " << car.number 
           << " | OwnerID: " << car.ownerId << "]";
        return os;
    }
};

// Helper function to display the stack contents
// Note: We pass by value to create a copy, so the original stack is not emptied
void printWarehouseState(stack<Auto> tempStack) {
    cout << "Current Warehouse State (Top to Bottom):" << endl;
    if (tempStack.empty()) {
        cout << "  (Warehouse is empty)" << endl;
    }
    
    while (!tempStack.empty()) {
        cout << "  " << tempStack.top() << endl;
        tempStack.pop();
    }
    cout << "----------------------------------------" << endl;
}

int t19_10g() {
    stack<Auto> warehouse;

    cout << "=== WAREHOUSE SIMULATION (STACK LIFO) ===" << endl;

    // 1. Fill the warehouse (Push)
    cout << "\n[ACTION] Adding Toyota Camry..." << endl;
    warehouse.push(Auto("Toyota", "Camry", "AA0001AA", 101));
    printWarehouseState(warehouse);

    cout << "\n[ACTION] Adding BMW X5..." << endl;
    warehouse.push(Auto("BMW", "X5", "BB0002BB", 102));
    printWarehouseState(warehouse);

    cout << "\n[ACTION] Adding Audi A6..." << endl;
    warehouse.push(Auto("Audi", "A6", "CC0003CC", 103));
    printWarehouseState(warehouse);

    // 2. Remove from warehouse (Pop)
    cout << "\n[ACTION] Shipping out last added car (Audi)..." << endl;
    if (!warehouse.empty()) {
        warehouse.pop();
    }
    printWarehouseState(warehouse);

    cout << "\n[ACTION] Shipping out next car (BMW)..." << endl;
    if (!warehouse.empty()) {
        warehouse.pop();
    }
    printWarehouseState(warehouse);

    cout << "\n[ACTION] Shipping out last car (Toyota)..." << endl;
    if (!warehouse.empty()) {
        warehouse.pop();
    }
    printWarehouseState(warehouse);

    return 0;
}