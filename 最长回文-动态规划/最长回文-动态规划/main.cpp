#include<iostream>
#include<string>
using namespace std;

//动态规划 时间复杂度O(N2), 空间复杂度O(N2)
//动态规划就是暴力法的进化版本，我们没有必要对每一个子串都重新计算，看看它是不是回文。我们可以记录一些我们需要的东西，
//就可以在O（1）的时间判断出该子串是不是一个回文。这样就比暴力法节省了O（N）的时间复杂度哦，嘿嘿，其实优化很简单吧。
//P（i，j）为true时代表字符串Si到Sj是一个回文，为false时代表字符串Si到Sj不是一个回文。
//P（i，j） = P（i + 1，j - 1）（如果S[i] = S[j]）。这是动态规划的状态转移方程。
//P（i，i） = true，P（i，i + 1） = true (if（S[i] = S[i + 1]）)
int GetMaxLength(const string &str,bool **p,const int length)
{
	int maxLen;
	int end = 0;
	for (int len = 3;len <= length;len++)
	{
		for (int start = 0;start <= length - len;start++)
		{
			end = start + len - 1;					//子串结束位置
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