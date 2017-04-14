#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//这个就是因为求的是两个最大值的差, 所以肯定可以找到整个数组的最大值, 
//然后就可以确定一边的最大值了, 另一边的最大值就是要找左右两端最小那个数,
//因为无论他们怎么往外扩都只能增大, 不能减小,
//所以最大差值就是第一次找出来的最大值和左右两边小的那个数的差了

int findMaxGap(vector<int>&value, int n)
{
	if (0 >= n)
	{
		return -1;
	}
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0;i < n; i++)
	{
		if (max < value[i])
		{
			max = value[i];
		}
	}
	min = value[0] > value[n - 1] ? value[n - 1] : value[0];
	return (max - min);

}

int main()
{
	vector<int>value;
	int n;
	char c;
	while (1)
	{
		cin >> n;
		value.push_back(n);
		c = cin.get();
		if (c == '\n') break;
	}
	cout << findMaxGap(value, value.size())<<endl;
	return 0;
}