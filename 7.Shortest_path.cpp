#include <iostream>
using namespace std;
double min(double a, double b)
{
    if (a >= b)
    {
        return b;
    }
        return a;
}
double dlinaputi(int i, int j, double **prkst, bool **etoskver)
{
    if (prkst[i][j] != -1) // если расстояние до пнрекрестка известно по условию задачи(оно проходит вдоль оси n/i или m/j)
    {
        return prkst[i][j]; // фиксируем это расстояние известными значениями
    }
    if (etoskver[i][j]) // если на перекрестке n,m есть сквер
    {
        double temp = dlinaputi(i - 1, j - 1, prkst, etoskver); // длина пути до перекрестка n-1,m-1*/
        prkst[i][j] = temp + 141.4213;  // длина пути до предыдущего перекрестка увеличивается на расстояние по диагонали
        return prkst[i][j];
    }
    double temp1 = dlinaputi(i - 1, j, prkst, etoskver);// длина пути до перекрестка n-1,m
    double temp2 = dlinaputi(i, j - 1, prkst, etoskver);// длина пути до перекрестка n,m-1
    prkst[i][j] = min(temp1, temp2) + 100;//выбор минимального пути на последнем квадрате n,m
    return prkst[i][j];
}
void shortest_path(int n, int m)
{
    double **prkst = new double*[n + 1]; //двумерный массив минимальных расстояний из дома до очередного перекрестка
    bool **etoskver = new bool*[n + 1]; // двумерный массив скверов уменьшает расстояние до очередного перекрестка с 200 до 141
    for (int i = 0; i <= n; i++)
    {
        etoskver[i] = new bool[m + 1];
        prkst[i] = new double[m + 1];
    }
    for (int i = 0; i < m + 1; i++) // разметка кварталов - кратчайшее расстояние из дома до перекрестка
    {
        for (int j = 0; j < n + 1; j++) //по вертикали
        {
            etoskver[j][i] = false; // место сквера неизвестно
            prkst[j][i] = -1; // расстояние неизвестно
            prkst[j][0] = 100 * j;   //  расстояние до пнрекрестка известно по условию задачи(оно проходит вдоль оси n/i или m/j)
        }
        prkst[0][i] = 100 * i; // по гризонтали
    }
    int kolvoskver;
	cin >> kolvoskver;
    for (int i = 0; i < kolvoskver; i++)  // разметка скверов
    {
        int n_i, m_i;
        cin >> n_i >> m_i;
        etoskver[n_i][m_i] = true;
    }
    cout << (int)(dlinaputi(n, m, prkst, etoskver) + 0.5);
}
int main()
{
    int n, m;
    cin >> n >> m;
    shortest_path(n, m);
    return 0;
}
