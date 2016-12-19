#include <iostream>

using namespace std;

int **dig_trench(int **Mas, int size)
{
    int e;
    for (int i = 1; i <= size; i++)
        for (int l = 1; l <= size; l++)
    {
        if (i >= l)
            e = i - l;
        else
            e = l - i;
        Mas[i][l] = e;
    }
    return Mas;
}

int main()
{
int n;
 cin >> n;
 int **Trench = new int*[n];
 for (int i = 1; i <= n; i++)
    Trench[i] = new int[n];
 Trench = dig_trench(Trench, n);
 for (int i = 1; i <= n; i++)
 {
  for (int l = 1; l <= n; l++)
  {
      cout << Trench[i][l] << " ";
  }
  cout << endl;
 }
    return 0;
}
