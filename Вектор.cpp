#include <iostream>

using namespace std;

class vector
{
    int* Array;
    int size;
    int m;

public:
    vector(int n)
    {
        Array = new int[n];
        size = n;
        m = 0;
    }

    void push(int a)
    {
        if (size <= m)
        {
            add(2 * size);
            size = size * 2;
        }
        Array[m] = a;
        m++;
    }

    int Size()
    {
        return m;
    }

    int find(int a)
    {
        int i = 0;
        while((a != Array[i]) && (Array[i=1] != '\0'))
            i++;
        if(a == Array[i])
            return i;
        return -1;
    }

    void del(int a)
    {
        for (int i = 0; i < m; i++)
            if (Array[i] == a)
        {
            for (int l = i; l < m - 1; l++)
                Array[l] = Array[l + 1];
            Array[m - 1] = '\0';
            m--;
        }
    }

    void add(int Size)
    {
        int* ARRAY = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            ARRAY[i] = Array[i];
        }
        Array = ARRAY;
    }
    int& operator[](const int i)
    {
        int k = 1;
        if((i < m) && (i > -1))
            return Array[i-1];
            if (i < 0)
                k = -1;
            cout << "ERROR!" << endl;
            if (k == 1)
                return Array[i % m];
           return Array[-i % m];
    }
    ~vector()
    {
        delete Array;
    }
};

int main()
{
    int n;
    cin >> n;
    vector object(n);
    object.push(n);
    object.push(n + 1);
    object.push(n + 2);
    object[2] = n + 1;
    cout << object.Size() << endl;
    cout << object.find(n + 1) << endl;
    cout << object[2] << endl;
    return 0;
}
