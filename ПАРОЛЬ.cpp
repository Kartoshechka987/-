#include <iostream>

using namespace std;

int a, b, c, d, e, f, g, h, i, j, k, l;

int main()
{
    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
        for (c = 0; c < 10; c++)
        if ((a + b + c) % 2 == 0)
        for (d = 0; d < 10; d++)
        for (e = 0; e < 10; e++)
        for (f = 0; f < 10; f++)
        if (b + d + f == 21)
        for (g = 0; g < 10; g++)
        for (h = 0; h < 10; h++)
       if (b + d + f + h == 21)
       for (i = 0; i < 10; i++)
       for (j = 0; j < 10; j++)
       if (b + d + f + h + j == 21)
       for (k = 0; k < 10; k++)
       for (l = 0; l < 10; l++)
       if (b + d + f + h + j + l == 21 && (j + k + l) % 3 == 0 && (c + f + i + l) % 11 == 0)
       cout << a << b << c << d << e << f << g << h << i << j << k << l << endl;
    return 0;
}
