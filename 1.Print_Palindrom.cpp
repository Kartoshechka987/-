#include <iostream>
#include <cmath>

using namespace std;
void print_palindrom(int n)
{
    int i, j, na, ko, otvet=0, k;
    na=pow(10,(n-1)); // n-значные числа начинаются
    ko=pow(10,n)-1; // n-значные числа завершаются
    while (na<=ko+1)
    {     // перебор n-значных чисел от начала до конца
        j=n;
        otvet=0;           // счетчик совпадений цифр в числе, симметричных относительно середины
        for (i=1; i<=(n/2); i++)
        {         // перебор с начального разряда до середины n-значного числа
            if  ( ( (int) (na/pow(10,i-1)) %10 )  == ( (int) (na/pow(10,j-1)) %10 ) )
            {  // если цифры совпали,
                otvet++;  // то увеличить счетчик совпадений
            }
            j--;                          // перебор с конечного разряда до середины
            if (otvet == n/2 && na%9 == 0)// если одна половина цифр в числе совпала с другой симметричной половиной и число делитля на 9,
            {
                 cout << na <<" ";        // то надо вывести число-палиндром на экран
            }
        }
        na++;     // перебор - переход к следющеу числу
    }
}

int main() {

    int m;
    cin >> m;
    cout << endl;
    print_palindrom(m); // вызов процедуры печати палиндрома
    return 0;
}

