#include<iostream>
#include<string>
using namespace std;


//这里用到了：翻转子串 == 原子串 = >回文子串
//从原串的开头开始找，比较是否与翻转串的末尾相同
//这里用到了本题的特征：已有的回文子串肯定出现在末尾，不会出现在中间】
//Example：
//原串      abcdedc
//翻转串       cdedcba

string  addToPalindrome(string &str, unsigned int n) 
{
	string strTemp = str;
	int addStrLocation = 0;
	reverse(strTemp.begin(), strTemp.end());
	for (unsigned int i = 0,j = 0; i < strTemp.size() && j < str.size(); )
	{
		if (str[i] == str[j])
		{
			addStrLocation = j;
			i++;
			j++;
		}
		else
		{
			i = j + 1;
			j = 0;
			addStrLocation = 0;
		}
	}

	string s = "";
	for (unsigned int i = 0; i < str.size() - addStrLocation -1; i++)
	{
		s += str[i];
	}
	return s;
}

int main()
{
	string str;
	while (cin>>str)
	{
		cout << addToPalindrome(str, str.size())<<endl;
	}
}