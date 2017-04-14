#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long result = 0;
		long long first = 1;
		long long second = 1;
		for (int i = 2;i <= n;i++)
		{
			result = (first + second)% 1000000007;
			second = first;
			first = result;
		}

		cout <<result<< endl;
	}
}