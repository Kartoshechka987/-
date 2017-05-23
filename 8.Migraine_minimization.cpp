#include<iostream>
	#include <cmath>
	using namespace std;
	void Migraine_minimization(int n)
	{
		int maxkvadr, kolvo = 0;
		while (n > 0)
		{
			maxkvadr = (int)sqrt(n);
			n = n - maxkvadr*maxkvadr;
			kolvo = kolvo + 1;
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
