#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    int n;
    cin >> n;

    int **M = new int *[n+1];
    for(int i=0; i<n+1; i++)
        M[i] = new int[n+1];

    int **M2 = new int *[n+1];
    for(int i=0; i<n+1; i++)
        M2[i] = new int[n+1];

    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
        {
            M[i][j] = 0;
            M2[i][j] = 0;
        }

    string *list = new string[n+1];
    int max = 0;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        M[a][b]++;
        if(a != b)
            M[b][a]++;
        M2[i+1][b]++;
        if(a != b)
            M2[i+1][a]++;
        if(a > max) max = a;
        if(b > max) max = b;
        list[a] = list[a] + (char)(b+48) + ",";
        list[b] = list[b] + (char)(a+48) + ",";
    }
    cout << endl;

    cout << "Список смежности: " << endl;
    for(int i=1; i<max; i++)
        cout << i << ": " << list[i] << endl;
    cout << endl << endl;

    cout << "Матрица инциденций: " << endl;
    for(int i=1; i<max+1; i++)
    {
        for(int j=1; j<max+1; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
