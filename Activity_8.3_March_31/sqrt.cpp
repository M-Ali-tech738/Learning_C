/*
* This program shows the various ways the
* sqrt function can be used.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
double x = 16.0;
// Pass a literal value and display the result
cout << sqrt(16.0) << endl;
// Pass a variable and display the result
cout << sqrt(x) << endl;
// Pass an expression
cout << sqrt(2 * x - 5) << endl;
// Assign result to variable
double y = sqrt(x);
// Use result in an expression
y = 2 * sqrt(x + 16) - 4;
// Use result as argument to a function call
y = sqrt(sqrt(256.0));
cout << y << endl;
}
