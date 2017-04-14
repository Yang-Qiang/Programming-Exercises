#include<iostream>
using namespace std;
int main()
{
	int inputnum;
	int result = 0;
	int a[10] = { 0 };
	cin >> inputnum;
	do {
		if (a[inputnum%10] == 0) {
			result = result * 10+ inputnum % 10;;
			if (0 == result) {
				inputnum /= 10;
				continue;
			}
			a[inputnum % 10]++;
		}
		inputnum /= 10;
	} while (inputnum != 0);
	
	cout << result;
}