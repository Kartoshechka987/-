
#include <iostream>
using namespace std;

int** C;
int* A;
int* B;
int timer = 0, n, m;
int* fup;
int* tin;
int* used;
int rebr(int a, int b)
{
    for(int i = 0; i < n; i++)
        if((A[i]==a&&B[i]==b)||(A[i]==b&&B[i]==a))
            return i;
}

void dfs(int v, int p=-1)
{
    used[v] = 1;
    tin[v] = fup[v] = timer++;

    for(int i = 0; i < m; i++)
        if(C[v][i])
    {
        int t0 = i;

        if(t0 == p)
            continue;

        if(used[t0])
            fup[v] = min(fup[v], tin[t0]);
        else
        {
            dfs(t0, v);
            fup[v] = min(fup[v], fup[t0]);

            if(fup[t0] > tin[v])
                cout << rebr(v, t0) << " ";
        }
    }
}

void matrix_smew()
{
    C = new int*[m];

    for(int i = 0; i < m; i++)
        C[i] = new int[m];

    for(int l = 0; l < m; l++)
        for(int i = 0; i < n; i++)
        {
            if(A[i] == l)
                C[l][B[i]] = 1;
            if(B[i] == l)
                C[l][A[i]] = 1;
        }
}

int main()
{
    int n, m;

    cin >> n >> m;//n-кол-во ребер, m-вершин; нумерация с 0

    A = new int[n];
    B = new int[n];

    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i];

    tin = new int[m];
    fup = new int[m];
    used = new int[m];

    matrix_smew();
    dfs(0);

    return 0;
}
