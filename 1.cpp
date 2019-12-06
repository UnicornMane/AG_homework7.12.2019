/*Напишите функцию находящую корень монотонной вещественной функции f бинарным поиском(бисекцией).
Можно считать что корень обязательно существует. Корнем будем считать значение x, такое что |f(x)|<10^(-6).
В комментариях напишите, почему решение- эффективное*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double f(double& x)
{
	return x * x * x  - x * x  - 1;
}

auto main() -> int
{
	const double INF = 1e6;
	double r = 1e6, l = -INF;

	for (int i = 0; i < 100000; i++)
	{
		double m = (r + l) / 2;
		if (f(m) > 0)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	cout << setprecision(15) << fixed << l;
}
