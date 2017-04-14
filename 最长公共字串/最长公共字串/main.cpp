#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*
*�� �� ����get_max_sequence
*��    �ܣ����������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд
*���������str_a ��һ���ַ���
		   str_b �ڶ����ַ���
*�������: len �����ĳ���
*�� �� ֵ��max_len �����ַ�������󹫹��ִ��ĳ���
*/
int get_max_sequence(const string &str_a, const string &str_b, int **len)
{
	int max_len = 0;
	int len_a = str_a.size();
	int len_b = str_b.size();
	for (int i = 1;i <= len_a;i++)
	{
		for (int j = 1;j <= len_b;j++)
		{
			if (str_a[i-1] == str_b[j-1]||abs(str_a[i-1]-str_b[j-1])==32)
			{
				len[i][j] = len[i - 1][j - 1] + 1;
				if (max_len < len[i][j]) max_len = len[i][j];
			}
		}
	}
	return max_len;
}

int main()
{
	string str_a;
	string str_b;
	while (cin>>str_a>>str_b)
	{
		int len_a = str_a.size();
		int len_b = str_b.size();
		int **len = new int *[len_a + 1];
		for (int i = 0;i <= len_a;i++)
		{
			len[i] = (int *)malloc(sizeof(int)*(len_b + 1));
		}

		for (int i = 0;i <= len_a;i++)
		{
			for (int j = 0;j <= len_b;j++)
			{
				len[i][j] = 0;
			}
		}

		cout << get_max_sequence(str_a, str_b,len)<<endl;
		for (int i = 0;i <= len_a;i++)
		{
			delete []len[i];
		}
		delete []len;
	}
}