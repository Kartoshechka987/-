#include <iostream>

	using namespace std;

	void qsort(int b, int e, double** &cena)
	{
		int l = b, r = e;
		int piv = cena[(l + r) / 2][0];
		while (l <= r)
		{
			while (cena[l][0] < piv)
				l++;
			while (cena[r][0] > piv)
				r--;
			if (l <= r)
				swap(cena[l++], cena[r--]);
		}
		if (b < r)
			qsort(b, r, cena);
		if (e > l)
			qsort(l, e, cena);
	}
	void Continuous_knapsack(double Vrukzaka, int n)
	{
		double **cena = new double*[n];
		for (int count = 0; count < n; count++)
			cena[count] = new double[4]; // ценность, вес, цена, номер в массиве
		double *otvet = new double[n];
		for (int i = 0; i < n; i++)
		{
			otvet[i] = 0;
		}
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			double v, c; // вес, цена
			cin >> v >> c;
			cena[i][0] = c / v;
			cena[i][1] = v;
			cena[i][2] = c;
			cena[i][3] = i;
		}
		qsort(0, n-1, cena);
		for (int i = n - 1; i >= 0; i--)
		{
			if (cena[i][1] >= Vrukzaka)
			{
				otvet[(int)cena[i][3]] = (cena[i][1] - Vrukzaka) / cena[i][1];
				Vrukzaka = 0;
				sum = sum + cena[i][2] * ((cena[i][1] - Vrukzaka) / cena[i][1]);
				break;
			}
			else
			{
				otvet[(int)cena[i][3]] = 1;
				Vrukzaka = Vrukzaka - cena[i][1];
				sum = sum + cena[i][2];
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << otvet[i] << " ";
		}
		cout << sum;
	}
	int main()
	{
		int n;
		double w;
		cin >> w >> n;
		Continuous_knapsack(w, n);
		return 0;
	}
