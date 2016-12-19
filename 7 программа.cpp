#include <iostream>

using namespace std;

int strange_multiply(int a, int n)
{
 if (n == 0 || a == 0)
        return 0;
 if (n % 2 == 1)
    return strange_multiply(a, n - 1) + a;
 else {
    int b = strange_multiply(a, n/2);
    return b+b;
 }
}

int main()
{
int n, a;
cin >> a >> n;
cout << strange_multiply(a, n);
    return 0;
}
