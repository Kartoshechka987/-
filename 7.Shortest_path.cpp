#include <iostream>
	using namespace std;
	double min(double a, double b)
	{
		if (a >= b)
		{
			return b;
		}
			return a;
	}
	double dlinaputi(int i, int j, double **prkst, bool **etoskver)
	{
		if (prkst[i][j] != -1)
		{
			return prkst[i][j];
		}
		if (etoskver[i][j])
		{
			prkst[i][j] = min(min(dlinaputi(i - 1, j, prkst, etoskver), dlinaputi(i, j - 1, prkst, etoskver)) + 100, dlinaputi(i - 1, j - 1, prkst, etoskver) + 141.4213);
			return prkst[i][j];
		}
		prkst[i][j] = min(dlinaputi(i - 1, j, prkst, etoskver), dlinaputi(i, j - 1, prkst, etoskver)) + 100;
		return prkst[i][j];
	}
	void shortest_path(int n, int m)
	{
		double **prkst = new double*[n + 1];
		bool **etoskver = new bool*[n + 1];
		for (int count = 0; count <= n; count++)
		{
			etoskver[count] = new bool[m + 1];
			prkst[count] = new double[m + 1];
		}
		for (int i = 0; i < m + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				etoskver[j][i] = false;
				prkst[j][i] = -1;
				prkst[j][0] = 100 * j;
			}
			prkst[0][i] = 100 * i;
		}
		int kolvoparkov;
		cin >> kolvoparkov;
		for (int i = 0; i < kolvoparkov; i++)
		{
			int n_i, m_i;
			cin >> n_i >> m_i;
			etoskver[n_i][m_i] = true;
		}
		cout << (int)(dlinaputi(n, m, prkst, etoskver) + 0.5);
	}
	int main()
	{
		int n, m;
		cin >> n >> m;
		shortest_path(n, m);
		return 0;
	}
