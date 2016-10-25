#include <iostream>

using namespace std;

int NOD(int a, int b)
 {
if (a==0)
    return b;
else
return NOD(b%a, a);
}

int NOK (int a, int b)
{
return (a*b/NOD(a,b));
}

int main (){

int a, int b;

cout<< "a= ";
cin>>a;

cout<< "b= ";
cin>>b;

cout<<NOK(a,b);
cin.get();
return 0;
}
