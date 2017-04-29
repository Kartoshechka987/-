#include <iostream>

using namespace std;

int main()
{
int a, b, n, m, l, k, d, e;
a = 3557;
b = 2579;
m = 100000;
l = 1;
k = 1;
d = 1;
e = 3;
n = a*b;

while ((d*e) % ((a - 1)*(b - 1)) != 1)
    d++;

for (int i = 0; i < e; i++)
{
    l *= m;
    l %= n;
}

for (int i = 0; i < d; i++)
{
    k *= l;
    k %= n;
}
 cout << k;

    return 0;
}
