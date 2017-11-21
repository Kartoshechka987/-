#include <iostream>
#include <cmath>

using namespace std;

void cicl_rebr(int** C, int max, int s, int** &D, int n)
{
    for(int i = 0; i < max; i++)
        if(C[s][i] != 0 && D[s][i] != 1)
        {
            D[s][i] = 1;
            cicl_rebr(C, max, i, D, n);
        }

    int h = 1;

    while(s >= n*h)
        h++;

    cout << s-n*(h-1) << " ";
}

int main()
{
    int n, k;
    cin >> n >> k;

    int N = pow(n, k-1);
    int L = N / n;
    int** C = new int*[N];
    int** D = new int*[N];

    for(int i = 0; i < N; i++)
    {
        C[i] = new int[N];
        D[i] = new int[N];
    }

    for(int i = 0; i < N; i++)
    {
        int c = i - (i/L)*L;

        for(int l = 0; l < n; l++)
            C[i][c*n+l] = 1;
    }

    for(int i = 0; i < N; i++)
    {
        for(int l = 0; l < N; l++)
            cout << C[l][i] << " ";
        cout << endl;
    }

    cicl_rebr(C, N, 0, D, n);

    return 0;
}
