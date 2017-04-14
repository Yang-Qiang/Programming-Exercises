#include<iostream>
#include<vector>
using namespace std;

int howmany(int n)
{
	if (n == 0 || n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	return n / 3 + howmany(n / 3 + n % 3);
}

int main()
{
	int n;
	vector<int>bottle;
	while (cin>>n&&n!=0)
	{
		if (n < 0)
		{
			continue;
		}
		bottle.push_back(n);
	}
	for (unsigned int i = 0;i < bottle.size();i++)
	{
		cout << howmany(bottle[i])<<endl;
	}
}