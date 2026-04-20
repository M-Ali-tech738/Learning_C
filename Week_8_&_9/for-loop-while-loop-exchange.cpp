#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i;
    double num;

    // VERSION 1: do-while loop
    cout << "=== do-while version ===" << endl;
    i = 1;
    do
    {
        num = i;
        cout << "sqrt(" << i << ") = " << sqrt(num) << endl;
        i++;
    }
    while(i <= 10);

    // VERSION 2: for loop
    cout << "\n=== for loop version ===" << endl;
    for(i = 1; i <= 10; i++)
    {
        num = i;
        cout << "sqrt(" << i << ") = " << sqrt(num) << endl;
    }

    return 0;
}