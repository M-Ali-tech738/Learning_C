// Q3 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// Label statements numbered in execution order (1 = first to execute)

#include <iostream>
#include <cmath>
using namespace std;

int main() {

/* LABEL 1 */ int d = 1;                          // First statement to execute: initialize d

/* LABEL 2 */ cout << "d\t sqrt(d)" << endl;      // Print table header

/* LABEL 3 */ while (d <= 10)                     // Check loop condition (checked each iteration)
              {
/* LABEL 4 */     double result = sqrt(d);         // Calculate square root of d

/* LABEL 5 */     cout << d << "\t" << result << endl;  // Print d and its sqrt

/* LABEL 6 */     d++;                             // Increment d (then goes back to LABEL 3)
              }

/* LABEL 7 */ cout << "Done!" << endl;            // After loop ends, this executes last

              return 0;
}

/*
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  EXECUTION ORDER EXPLANATION:
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 
   LABEL 1 → runs once: int d = 1
   LABEL 2 → runs once: print header
   LABEL 3 → checked EVERY iteration: while (d <= 10)
              If TRUE  → go to LABEL 4
              If FALSE → jump to LABEL 7
   LABEL 4 → runs each iteration: compute sqrt(d)
   LABEL 5 → runs each iteration: print result
   LABEL 6 → runs each iteration: d++, then back to LABEL 3
   LABEL 7 → runs once after loop ends: print "Done!"
 
  Full trace for first 3 iterations:
 
            1 → 2 → 3(T) → 4 → 5 → 6
            → 3(T) → 4 → 5 → 6
            → 3(T) → 4 → 5 → 6
            ...
            → 3(F) → 7 → end
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 */
