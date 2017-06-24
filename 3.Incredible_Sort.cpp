#include <iostream>

using namespace std;

void  incredible_sort(int n, int k)
{
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		int chislo;
		cin >> chislo;
		if(chislo <= k) a[i] = chislo; else a[i] = 0; //если элемент превышает к, то массив заполняется нулем

	}
    for (int j=0; j<n; j++)
    {
        int num_max = j;  // номер максимального элемента
        //обработка - поиск маскимального элемента в еще неупорядоченной части
        for (int i=j; i<n; i++)
        {
            if (a[i]>a[num_max])
            {
                num_max=i;
            }
        }
       int temp=a[j];
        a[j]=a[num_max];
        a[num_max]=temp;
    }
        for (int i=0; i<n; i++)
        {
            if (a[i] != 0)
                cout << a[i]<<" ";
        }

}
int main()
{
	int n, k;
	cin >> n >> k;
	incredible_sort(n, k);
	return 0;
}
