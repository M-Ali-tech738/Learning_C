#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "x (radians)\t sin(x)\n";
    cout << "---------------------\n";

    for (double x = 0; x <= 3.14; x += 0.01) {
       double a= sin(x);
        cout << x << "\t\t" << a << endl;
    }

    return 0;
}
