#include <iostream>

using namespace std;

int **build_ziggurat(int **Array, int size)
{
    for (int j = 1; j <= size; j++)
        for (int i = j; i <= size - j + 1; i++)
        for (int l = j; l <= size - j + 1; l++)
        Array[i][l] = j;
    return Array;
}

int main()
{
int n;
cin >> n;
int **ziggurat = new int*[n];
for (int i = 1; i <= n; i++)
    ziggurat[i] = new int[n];
ziggurat = build_ziggurat(ziggurat, n);
for (int i = 1; i <= n; i++)
{
    for (int l = 1; l <= n; l++)
    {
        cout << ziggurat[i][l];
    }
    cout << endl;
}
    return 0;
}
