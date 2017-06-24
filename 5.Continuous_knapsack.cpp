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
		double *otvet = new double[n];
		for (int i = 0; i < n; i++)		{
			cena[i] = new double[n];               // ценность, вес, цена, номер в массиве
        	otvet[i] = 0;                          // массив долей предметов, помещенных в рюкзак
		}
		double sum = 0;
		for (int i = 0; i < n; i++)		{
			double v, c; // вес, цена
			cin >> v >> c;
			cena[i][0] = c / v;                    // массив ценности предметов на единицу объема
			cena[i][1] = v;                        // массив объема предметов
			cena[i][2] = c;                        // массив стоимости предметов
			cena[i][3] = i;                        // массив номеров предметов в порядке ввода
		}
		qsort(0, n-1, cena);                       // сортировка предметов по ценности
		for (int i = n - 1; i >= 0; i--)		{
			if (cena[i][1] >= Vrukzaka)                                   // если сободного места нет,
			{
				otvet[(int)cena[i][3]] =  Vrukzaka / cena[i][1];          // вычисляем долю предмета как частное от деления оставшегося объема в рюкзаке на вес предмета
				sum = sum + cena[i][2] * Vrukzaka / cena[i][1];           // стоимость наполнения рюкзака увеличивается на долю не целого предмета
				Vrukzaka = 0;                                             // оставшийся свободным объем рюкзака надо обнулить
				break;			}
			else			{                                             // перебор предметов и наполнение рюкзака наиболее ценными
				otvet[(int)cena[i][3]] = 1;                               // доля этого целого предмета = 1
				Vrukzaka = Vrukzaka - cena[i][1];                         // осталось наполнить объем в рюкзаке
				sum = sum + cena[i][2];                                   // стоимость наполнения увеличивается на стоимость предмета, для которого место осталось
			}
		}
		for (int i = 0; i < n; i++)		{
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
