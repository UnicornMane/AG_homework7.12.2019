#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять принадлежность
 *пары значений массиву. Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет.
 *Можно считать, что количество запросов многократно превышает размер массива.
 *В комментариях напишите, почему перебор - эффективное*/

bool bSearch(vector <int> &arr, int &x)
{
	int r = arr.size();
	int l = 0;
	while (r - l > 1)
	{
		int m = (r + l) / 2;
		if (arr[m] > x)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	if (arr[l] == x)
		return true;
	return false;
}

int main()
{
	int f, s;
	cin >> f >> s;
	int n;
	cin >> n;
	vector <int> arr(n);
	arr.shrink_to_fit();
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	if (bSearch(arr, f) && bSearch(arr, s))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
