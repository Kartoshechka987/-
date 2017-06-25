    #include<iostream>
	#include <cmath>
	using namespace std;
	void Migraine_minimization(int n)
	{
		int maxkvadr, kolvo = 0;
		while (n > 0)
		{
			maxkvadr = (int)sqrt(n); //наибольший квадрат целого числа
			n = n - maxkvadr*maxkvadr; //остаток от вычитания очередного крадратного участка из нее
			kolvo++;
		}
		cout << 4 * kolvo;
	}
	int main()
	{
		int n;
		cin >> n;
		Migraine_minimization(n);
		return 0;
	}
