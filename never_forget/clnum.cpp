// write a program that classifies a number into negative even & odd and positive even and odd and zero
# include <iostream>
using namespace std;

int main() {

int a;

cout << "Enter any number you desire: ";
cin >> a;

if(a==0){
cout << "the number is zero";
}
else if(a%2==0){
if(a>0){
cout << "The number is positive even";
}
else 
cout << "The number is negative even";
}
else if(a%2!=0){
if(a>0){
cout << "The number is positive odd";
}
else 
cout << "The number is negative odd";
}

return 0;
} 
