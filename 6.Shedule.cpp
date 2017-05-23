#include <iostream>
	using namespace std;
	void qsort(int b, int e, int *&index, int *&fin)
	{
		int l = b, r = e;
		int piv = fin[index[(l + r) / 2]];
		while (l <= r)
		{
			while (fin[index[l]] < piv)
				l++;
			while (fin[index[r]] > piv)
				r--;
			if (l <= r)
				swap(index[l++], index[r--]);
		}
		if (b < r)
			qsort(b, r, index, fin);
		if (e > l)
			qsort(l, e, index, fin);
	}
	void shedule(int n)
	{
		int *index = new int[n];
		int *st = new int[n];
		int *fin = new int[n];
		int kolvo = 1, pred = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> st[i] >> fin[i];
			index[i] = i;
		}
		qsort(0, n - 1, index, fin);
		for (int i = 0; i < n; i++)
		{
			if (st[index[i]] >= fin[index[pred]])
			{
				pred = i;
				kolvo = kolvo + 1;
			}
		}
		cout << kolvo;
	}
	int main()
	{
		int n;
		cin >> n;
		shedule(n);
		return 0;
	}
