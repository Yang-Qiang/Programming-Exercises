#include<iostream>
#include<string>
using namespace std;


//�����õ��ˣ���ת�Ӵ� == ԭ�Ӵ� = >�����Ӵ�
//��ԭ���Ŀ�ͷ��ʼ�ң��Ƚ��Ƿ��뷭ת����ĩβ��ͬ
//�����õ��˱�������������еĻ����Ӵ��϶�������ĩβ������������м䡿
//Example��
//ԭ��      abcdedc
//��ת��       cdedcba

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