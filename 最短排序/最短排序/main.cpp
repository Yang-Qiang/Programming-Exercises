#include <iostream>
#include<vector>
using namespace std;

//˼·��1.���ж�������Сֵ�Ƿ�����ȷλ�ã�ֱ���ҵ�������ȷλ����Сֵ��Ӧ���ڵ�λ�ã���Ϊ��С���������ʼ��
//2.�����ж����ֵ�Ƿ�����ȷλ�ã�ֱ���Ҳ�����ȷλ�����ֵӦ���ڵ�λ�ã���Ϊ��С�������ĩβ��
//3.������ĩλ����������������Ϊ��Ҫ�������������鳤��

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
