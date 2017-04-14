#include<iostream>
#include<string>
using namespace std;

//��̬�滮 ʱ�临�Ӷ�O(N2), �ռ临�Ӷ�O(N2)
//��̬�滮���Ǳ������Ľ����汾������û�б�Ҫ��ÿһ���Ӵ������¼��㣬�������ǲ��ǻ��ġ����ǿ��Լ�¼һЩ������Ҫ�Ķ�����
//�Ϳ�����O��1����ʱ���жϳ����Ӵ��ǲ���һ�����ġ������ͱȱ�������ʡ��O��N����ʱ�临�Ӷ�Ŷ���ٺ٣���ʵ�Ż��ܼ򵥰ɡ�
//P��i��j��Ϊtrueʱ�����ַ���Si��Sj��һ�����ģ�Ϊfalseʱ�����ַ���Si��Sj����һ�����ġ�
//P��i��j�� = P��i + 1��j - 1�������S[i] = S[j]�������Ƕ�̬�滮��״̬ת�Ʒ��̡�
//P��i��i�� = true��P��i��i + 1�� = true (if��S[i] = S[i + 1]��)
int GetMaxLength(const string &str,bool **p,const int length)
{
	int maxLen;
	int end = 0;
	for (int len = 3;len <= length;len++)
	{
		for (int start = 0;start <= length - len;start++)
		{
			end = start + len - 1;					//�Ӵ�����λ��
			if (p[start + 1][end - 1] && str[start] == str[end])
			{
				p[start][end] = true;
				maxLen = len;
			}
		}
	}
	return maxLen;
}

int main()
{
	string str;
	int maxLen = 0;
	while (cin>>str)
	{
		int len = str.length();
		bool **p = new bool*[len];
		for (int i = 0;i < len;i++)
		{
			p[i] = new bool[len];
		}

		for (int i = 0;i < len;i++)
			for (int j = 0;j < len;j++)
			{
				p[i][j] = false;
				maxLen = 2;
			}

		for (int i = 0;i < len;i++)
		{
			p[i][i] = true;
		}
		for (int i = 0;i < len - 1;i++)
		{
			if (str[i] == str[i + 1])
				p[i][i + 1] = true;
		}

		cout << GetMaxLength(str, p, len)<<endl;

		for (int i = 0;i < len;i++)
		{
			delete[]p[i];
		}
		delete []p;
	}
	return 0;
}