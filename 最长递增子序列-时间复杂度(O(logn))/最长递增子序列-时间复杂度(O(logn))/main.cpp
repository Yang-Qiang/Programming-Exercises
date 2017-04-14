#include <iostream>
#include<vector>
#include<string>
using namespace std;

int findInsertPos(int *B, int value, int start, int end)
{
	int mid = start + (end - start) / 2;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (B[mid] < value)
		{
			start = mid + 1;
		}
		else if (B[mid] > value)
		{
			end = mid;				//被替换的可能是B[mid],所以end != mid - 1
		}
		else return mid;
	}
	return start;
}

int findLongest(vector<int>&A, int len)
{
	int end = 0;
	int pos = 0;
	int *B = new int[len];
	B[0] = A[0];
	for (int i = 1;i < len; i++)
	{
		if (A[i] > B[end])
		{
			B[++end] = A[i];
		}
		else
		{
			pos = findInsertPos(B, A[i], 0, end);
			B[pos] = A[i];
		}
	}
	return end + 1;
}

int main()
{
	vector<int>A;
	int i = 0;
	char c;
	while (1)
	{
		cin >> i;
		A.push_back(i);
		c = cin.get();
		if (c == '\n') break;
	}
	cout << findLongest(A, A.size()) << endl;
	return 0;
}
