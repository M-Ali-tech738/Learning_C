#include<iostream>
using namespace std;

int main() {
    int Supplier_Quantity[4], NumberOfDays, OverallTotal = 0;

    cout << "Enter Number of Days: ";
    cin >> NumberOfDays;

    for (int i = 0; i < NumberOfDays; i++) {
        int dailySum = 0;
        for (int j = 0; j < 4; j++) {
            cout << "Day " << i + 1 << "Enter Milk Quantity from Supplier_" << j + 1 << ": ";
            cin >> Supplier_Quantity[j];
            dailySum += Supplier_Quantity[j];
}
        OverallTotal += dailySum;
        cout << "Total for Day " << i + 1 << ": " << dailySum << "\n";
    }

    cout << "Total milk receieved in " <<NumberOfDays <<" days: " << OverallTotal << endl;
    return 0;
}
