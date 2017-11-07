#include <iostream>
#include <windows.h>

using namespace std;

void prov_sviz(int** C, int max, int k, int* &D)
{
    if(D[k] == 1)
    return;

    D[k] = 1;
    for(int i = 0; i < max; i++)
        if(C[k+1][i] != 0)
            prov_sviz(C, max, i, D);
}

int main()
{
    SetConsoleOutputCP(1251);
    int n, max = 0, j = 1;
    cin >> n;

    int* A = new int(n);
    int* B = new int(n);

    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i];

    for(int i = 0; i < n; i++)
    {
        if(max < A[i])
        max = A[i];
        if(max < B[i])
        max = B[i];
    }

    int* D = new int(max);
    D[0] = 1;
    int** C = new int*[max];

    for(int i = 1; i <= max; i++)
        C[i] = new int(max);

    for(int t = 1; t <= max; t++)
    {
        for(int i = 0; i < n; i++)
        {
            if(A[i] == t)
            {
                C[t][j] = B[i];
                j++;
            }

            if(B[i] == t)
            {
                C[t][j] = A[i];
                j++;
            }
        }

        j = 1;
    }

    for(int i = 1; i <= max; i++)
    {
        for(int l = 1; l <= max; l++)
            if(C[i][l] != 0)
                cout << C[i][l] << " ";
        cout << endl;
    }

    prov_sviz(C, max, 1, D);

    int g = 0;

    for(int i = 0; i < max; i++)
        if(D[i] == 1)
            g++;

    if(g == max)
        cout << "Есть компонентная связность";
    else cout << "Нет компонентной связности";

    return 0;
}

