#include <iostream>

using namespace std;

int main()
{
  int b;

  cout<<"b= ";
  cin>>b;

  int *a = new int[b + 1];

  for (int i = 0; i < b+1; i++)
    a[i] = i;

  for (int p = 2; p < b+1; p++)
    {
    if (a[p] != 0)
     {
      cout << a[p] << endl;

      for (int m = p*p; m < b + 1; m += p)
        a[j] = 0;
    }
  }
cin.get();
}
