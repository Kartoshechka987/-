#include <iostream>
#include <cmath>
using namespace std;
void perevernut(int x)
{
	while (x)
	{
		cout << x % 10;
		x = x / 10;
	}
}
void print_palindrom(int n)
{
	if (n % 2 == 0)
	{
		int i = pow(10, n / 2 - 1), chislo = i - 1;
		while (true)
		{
			chislo = chislo + 9;
			if (chislo / (10 * i) != 0) break;
			cout << chislo;
			perevernut(chislo);
			cout << " ";
		}
	}
	else
	{
		int i = pow(10, n / 2 - 1), chislo = i - 1;
		while (true)
		{
			chislo = chislo + 1;
			if (chislo / (10 * i) != 0) break;
			cout << chislo << 9 - ((chislo * 2) % 9);
			perevernut(chislo);
			cout << " ";
		}
	}
}
int main()
{
	int n;
	cin >> n;
	print_palindrom(n);
	return 0;
}
