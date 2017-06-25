#include <iostream>
	using namespace std;
	void qsort(int lo, int hi, int *&index, int *&fin)
	{
		int l = lo, r = hi;
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
		if (lo < r)
			qsort(lo, r, index, fin);
		if (hi > l)
			qsort(l, hi, index, fin);
	}
	void shedule(int n)
	{
		int *index = new int[n]; //массив порядковых номеров занятий
		int *st = new int[n]; //масств началаа занятия
		int *fin = new int[n]; //масств конца занятия
		int kolvo = 1, pred = 0; //колдичество подходящих заявок =1, потому что первая заявка будет подходящей; номер предыдущего подходящего занятия
		for (int i = 0; i < n; i++)
		{
			cin >> st[i] >> fin[i];
			index[i] = i;
		}
		qsort(0, n - 1, index, fin);//сортировка по времени  конца занятия
		for (int i = 0; i < n; i++)
		{
			if (st[index[i]] >= fin[index[pred]])  // если очередная заявка начинается позже либо одновременно со временем окончания предыдущей подходящей
			{
				pred = i;
