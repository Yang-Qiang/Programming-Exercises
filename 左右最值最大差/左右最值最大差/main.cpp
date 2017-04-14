#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//���������Ϊ������������ֵ�Ĳ�, ���Կ϶������ҵ�������������ֵ, 
//Ȼ��Ϳ���ȷ��һ�ߵ����ֵ��, ��һ�ߵ����ֵ����Ҫ������������С�Ǹ���,
//��Ϊ����������ô��������ֻ������, ���ܼ�С,
//��������ֵ���ǵ�һ���ҳ��������ֵ����������С���Ǹ����Ĳ���

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