// Q4 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// File: main.cpp  (Entry point - uses functions from functions.h/.cpp)

#include "functions.h"

int main() {

    cout << "=== Switch + Enum: Days of the Week ===" << endl;

    // Loop through all enum values using a for loop
    for (int i = MON; i <= SUN; i++) {
        printDay((Day)i);   // cast int to Day enum
    }

    cout << endl;
    cout << "=== setw Table: Powers of N ===" << endl;
    printTable(5);

    cout << endl;
    // Global variable usage
    cout << "Total function calls made: " << callCount << endl;

    return 0;
}
