#include <iostream>

using namespace std;

int BinPow (int a, int n)
 {
if (n%2==1)
    return 1/(BinPow(a,n-1)*a);

else
    {
    int b=1/BinPow (a,n-2);
    return b*b;
}
}
else
{
    if (n==0)
        return 1;

    if (n%2==1)
        return BinPow(a,n-1)*a;

    else
        {
        int b=BinPow(a,n/2);
        return b*b;
    }
}

int main () {
int n;
int a;
cin>>a;
cin>>n;
cout<<BinPow(a,n);
return 0;
}
