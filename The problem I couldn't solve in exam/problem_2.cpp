#include <iostream>
using namespace std;

int main()
{
bool t=true;
while(t){
int n,k;
char e;
k=0;
cout << "Enter a number: ";
cin >> n;
 
for(int i=2; i<n; i++)
{
int a= n%i;

if(a==0)
{
k+=1;
}

}

if (k==0)
{
cout << "A prime number ";
cout << endl;
}

else
{ 
cout << "Not a prime number";
cout << endl;
}

cout<<"Press "<<"'e'"<<" to exit"<<" or 'f' to continue: ";
cin >> e;
cout << endl;

if (e == 'e')
{
t=false;
}

}

return 0;
}
