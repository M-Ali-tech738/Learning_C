// Q4 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// File: functions.cpp  (Definitions of helper functions)

#include "functions.h"
#include <iomanip>   // for setw

// ---- GLOBAL VARIABLE DEFINITION ----
int callCount = 0;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// printDay: uses SWITCH + ENUM to print the day name
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printDay(Day d) {
    callCount++;  // increment global counter

    cout << "Day " << d << " is: ";

    // Switch statement on enum value
    switch (d) {
        case MON: cout << "Monday";    break;
        case TUE: cout << "Tuesday";   break;
        case WED: cout << "Wednesday"; break;
        case THU: cout << "Thursday";  break;
        case FRI: cout << "Friday";    break;
        case SAT: cout << "Saturday";  break;
        case SUN: cout << "Sunday";    break;
        default:  cout << "Unknown";   break;
    }
    cout << endl;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// printTable: uses setw to print a neatly aligned table
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printTable(int n) {
    callCount++;  // increment global counter

    // Local variable (only exists inside this function)
    int i;

    cout << setw(5) << "N"
         << setw(10) << "N*N"
         << setw(10) << "N*N*N" << endl;
    cout << string(25, '-') << endl;

    for (i = 1; i <= n; i++) {
        cout << setw(5)  << i
             << setw(10) << i * i
             << setw(10) << i * i * i << endl;
    }
}
