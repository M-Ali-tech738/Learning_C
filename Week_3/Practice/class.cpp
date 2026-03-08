#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Parameterized constructor
    Car(string brandName="Tesla", int yearValue=2022) {
        brand = brandName;
        year = yearValue;
        cout << "Parameterized constructor called!" << endl;
    }
};

int main() {
    // Calls the parameterized constructor with specific values
    Car myCar("Ford", 2020);
    Car Car1;
    cout << "My car is a " << myCar.brand << " from " << myCar.year << endl;
    cout << endl;
    cout << Car1.brand;
    cout << endl;
    return 0;
}
