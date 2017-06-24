#include <iostream>

using namespace std;

int NOD (int n, int m)
{ // фукция  поиска НОД
    while (m !=0) {
        int tmp = n % m;
        n= m;
        m = tmp;
    }
    return n;
}

void unusual_diofant(int a, int b, int c)
{

    int x, y;
    if (c%(NOD (a, b)) != 0)
    { // НОД a и b не делит с на цело
        cout <<"none"; //решений нет
    }
    else
    {
        for (x = 0; x <= (c/a); x++)    // пока by = c - ax > 0 для всех положительных x
        {
            if ( (c-a*x)%b==0 && (c-a*x)/b>0 )
            { // если y = (c-ax)/b целое положительное число
                y = (c-a*x) / b;                 // то вычисляем y
                cout << x << " " <<y <<endl; //Положительное решение диофантова уравнения
            }
            else if ( (  (-a) / NOD(a,b) ) > 0)
            {  // если коэффициент y=y0+ka/НОД(a,b) увеличивает y до бесконечност
                cout << "inf" ; // решений бесконечное количество
                break;
            }

        }
    }
}


int main()
{
    int a, b, c;
    cin >> a >> b >>c;
    unusual_diofant(a, b, c);
    return 0;
}

