#include <iostream>
using namespace std;

int main() 
{

int no_of_trucks, liters_of_crude_oil, NumberOfDays;
int CrudeOil, TotalCrudeOil;

no_of_trucks = 3;
liters_of_crude_oil = 50;
CrudeOil = no_of_trucks * liters_of_crude_oil ;
TotalCrudeOil=0;

cout << "Enter the number of days (1-7): ";
cout << endl;
cin >> NumberOfDays;
cout << endl;

for( int i=1; i <= NumberOfDays ; i++)
{
TotalCrudeOil+=CrudeOil ;
}

cout << "Total crude oil receieved in " << NumberOfDays << " days: " <<  TotalCrudeOil;
cout << endl;

//TotalCrudeOil = (no_of_trucks * liters_of_crude_oil)*NumberOfDays ;
//cout << endl;
//cout << TotalCrudeOil;

return 0;
}

