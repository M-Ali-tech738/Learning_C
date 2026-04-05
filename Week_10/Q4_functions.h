// Q4 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// File: functions.h  (Header file - declares functions and enum)

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

// ---- ENUM ----
// Defines named constants for days of the week
enum Day { MON=1, TUE, WED, THU, FRI, SAT, SUN };

// ---- GLOBAL VARIABLE ----
extern int callCount;   // Tracks how many times functions are called

// ---- FUNCTION DECLARATIONS ----
void printDay(Day d);
void printTable(int n);

#endif
