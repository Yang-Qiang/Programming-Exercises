#include <iostream>
#include<vector>
using namespace std;

//思路：1.先判断依次最小值是否在正确位置，直到找到不在正确位置最小值的应该在的位置，作为最小需排序的起始点
//2.依次判断最大值是否在正确位置，直到找不到正确位置最大值应该在的位置，作为最小需排序的末尾点
//3.计算首末位点间的整数个数，即为需要排序的最短子数组长度

int findShortest(vector<int> &num, int n) {
	int max = num[0];
	int maxPos = 0;
	int min = num[n - 1];
	int minPos = n - 1;
	for (int i = 1; i < n; i++)
	{
		if (max > num[i])
		{
			maxPos = i;
		}
		else
		{
			max = num[i];
		}
	}

	if (maxPos == 0)	return 0;

	for (int i = n - 2; i >= 0; i--)
	{
		if (min < num[i])
		{
			minPos = i;
		}
		else
		{
			min = num[i];
		}
	}

	return (maxPos - minPos + 1);
}

int main()
{
	int i = 0;
	vector<int>num;
	char c;
	while (1)
	{
		cin >> i;
		num.push_back(i);
		c = cin.get();
		if (c == '\n') break;
	}

	cout << findShortest(num, num.size());
	return 0;
}
