#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

/*void kStatistics(vector <int> &arr, int &k)
{
	nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
}
*/

int kStatistics(std::vector<int> a, int n, int k)
{
	for (int l = 1, r = n; ; )
	{

		if (r <= l + 1)
		{
			if (r == l + 1 && a[r] < a[l])
				swap(a[l], a[r]);
			return a[k];
		}


		int mid = (l + r) >> 1;
		swap(a[mid], a[l + 1]);
		
		if (a[l] > a[r])
			swap(a[l], a[r]);
		
		if (a[l + 1] > a[r])
			swap(a[l + 1], a[r]);
		
		if (a[l] > a[l + 1])
			swap(a[l], a[l + 1]);

		int i = l + 1, j = r;
		const int cur = a[l + 1];
		while(1)
		{
			while (a[++i] < cur);
			while (a[--j] > cur);
			if (i > j)
				break;
			swap(a[i], a[j]);
		}

		a[l + 1] = a[j];
		a[j] = cur;

		if (j >= k)
			r = j - 1;
		if (j <= k)
			l = i;

	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	--k;
	
	cout << arr[k];
}