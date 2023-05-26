#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    double x, xn, xk, dx, f1, f2, f3, min, x1, x2, xe1, xe2, dxe;
    int i, n, k;

    cout << "Введите xn,xk,dx " << endl;
    cin >> xn >> xk >> dx;

    n = (xk - xn) / dx + 1;
    x = xn;
    f2 = x * sin(3 * x) * cos(x);

    cout << endl << " x = " << x << "\t" << " f = " << f2 << endl;

    x += dx;
    f3 = x * sin(3 * x) * cos(x);

    cout << endl << " x = " << x << " \t" << " f = " << f3 << endl;

    k = 0;
    min = xk - xn;

    for (i = 2; i < n; i++)
    {
        f1 = f2;
        f2 = f3;
        x = xn + i * dx;
        f3 = x * sin(3 * x) * cos(x);

        cout << endl << " x = " << x << "\t" << " f = " << f3 << endl;

        if (f2 > f1 && f2 > f3)
        {
            k++;

            cout << endl << " k = " << k << " \t" << " x = " << x - dx << "\t" << " f = " << f2 << "\t" << "max " << endl;

            if (k == 1)
            {
                x1 = x - dx;
            }

            if (k > 1)
            {
                x2 = x - dx;
                dxe = x2 - x1;
                if (dxe < min)
                {
                    min = dxe; xe1 = x1; xe2 = x2;
                }
                x1 = x2;
            }
        }

        if (f2 < f1 && f2 < f3)
        {
            k++;

            cout << endl << " k = " << k << "\t" << " x = " << x - dx << "\t" << " f = " << f2 << "\t" << " min " << endl;

            if (k == 1)
            {
                x1 = x - dx;
            }

            if (k > 1)
            {
                x2 = x - dx;
                dxe = x2 - x1;

                if (dxe < min)
                {
                    min = dxe; xe1 = x1; xe2 = x2;
                }

                x1 = x2;
            }
        }
    }

    cout << endl << " Минимальное расстояние min = " << min << endl
        << " Первая точка искомого экстремума xe1 = " << xe1 << endl
        << " Вторая точка искомого экстремума xe2 = " << xe2 << endl;
    return 0;
}