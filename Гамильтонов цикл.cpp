#include <iostream>
#include <windows.h>

using namespace std;

void gam_cicl(int** C, int max, int s, int* &D)
{
    for(int i = 1; i <= max; i++)
        if(C[s][i] != 0 && D[i-1] != 1)
        {
            D[i-1] = 1;
            gam_cicl(C, max, C[s][i], D);
        }
    cout << s << " ";
}

int main()
{
    SetConsoleOutputCP(1251);
    int n, max = 0, j = 1;
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];

        if(max < A[i]) max = A[i];
        if(max < B[i]) max = B[i];
    }

    int* F = new int[max];

    for(int i = 0; i < n; i++)
    {
        F[A[i]-1]++;
        F[B[i]-1]++;
    }

    int* D = new int[max];
    int** C = new int*[max];

    for(int i = 1; i <= max; i++)
        C[i] = new int[max];

    for(int i = 1; i <= max; i++)
        for(int l = 1; l <= max; l++)
            C[i][l] = 0;
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

    int x = 0;

    for(int i = 0; i < max; i++)
        for(int l = 0; l < max; l++)
            if(F[i] == 1 || (F[i] + F[l] < max && i != l))
                x = 1;

    if(x == 1 || n < 3)
        cout << "нет цикла";
    else
    {
        cout << 1 << " ";
        gam_cicl(C, max, 1, D);
    }

    return 0;
}
