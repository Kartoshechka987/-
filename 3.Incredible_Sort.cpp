#include <iostream>
using namespace std;
void  incredible_sort(int n, int k)
{
	int *vsedok = new int[k];
	for (int i = 0; i < k; i++)
	{
		vsedok[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int chislo;
		cin >> chislo;
		vsedok[chislo - 1] = vsedok[chislo - 1] + 1;
	}
	for (int i = k - 1; i >= 0; i--)
	{
		if (vsedok[i] != 0)
		{
			for (int j = 0; j < vsedok[i]; i++)
			{
				cout << i + 1 << " ";
			}
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	incredible_sort(n, k);
	return 0;
}
