#include <iostream>

using namespace std;

int a[10];
void QuickSort(int l, int r)
int x = a[(r+l)/2];
int i = l;
int j = r;
while (i <= j)
{
while (a[i] < x)
i++;
while (a[j] > x)
j++;
if (i <= j)
{
    swap(a[i], a[j]);
    i++;
    j--;
}
}
if(i<r)
    QuickSort(i,r);
    if (l<j)
    QuickSort(l,j);

int main()
{
int n;
cin >>n;
for (int i = 0; i<n; i++)
{
   cin >> a[i];
}
QuickSort(0,n-1);
for (int i = 0; i<n; i++)
{
    cout << a[i] << "";
}
    return 0;
}
