#include <iostream>

using namespace std;

int NOD (int n, int m)
{ // ������  ������ ���
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
    { // ��� a � b �� ����� � �� ����
        cout <<"none"; //������� ���
    }
    else
    {
        for (x = 0; x <= (c/a); x++)    // ���� by = c - ax > 0 ��� ���� ������������� x
        {
            if ( (c-a*x)%b==0 && (c-a*x)/b>0 )
            { // ���� y = (c-ax)/b ����� ������������� �����
                y = (c-a*x) / b;                 // �� ��������� y
                cout << x << " " <<y <<endl; //������������� ������� ���������� ���������
            }
            else if ( (  (-a) / NOD(a,b) ) > 0)
            {  // ���� ����������� y=y0+ka/���(a,b) ����������� y �� ������������
                cout << "inf" ; // ������� ����������� ����������
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

