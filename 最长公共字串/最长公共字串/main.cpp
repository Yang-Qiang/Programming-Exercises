#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*
*函 数 名：get_max_sequence
*功    能：计算两个字符串的最大公共字串的长度，字符不区分大小写
*输入参数：str_a 第一个字符串
		   str_b 第二个字符串
*输出参数: len 存放最长的长度
*返 回 值：max_len 两个字符串的最大公共字串的长度
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