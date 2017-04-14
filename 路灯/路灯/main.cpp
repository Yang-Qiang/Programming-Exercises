#include<iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
	int a[10000];
	int n,l;
	int value;
	int minDis = 0;
	while (cin >> n >> l)
	{
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i = 1;i < n;i++)
		{
			if (minDis < a[i] - a[i - 1])
			{
				minDis = a[i] - a[i - 1];
			}
		}
		float result = minDis / 2.0;
		if (a[0]>result)
		{
			result = a[0];
		}
		if (l-a[n-1]>result)
		{
			result = l-a[n-1];
		}
		cout << result << endl;
	}
	return 0;

}