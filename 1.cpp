#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double f(double& x)
{
	return pow(x, 11) + 56 * x + 7;
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
	cout << setprecision(56) << fixed << l;
}
