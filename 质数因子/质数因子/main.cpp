#include<iostream>
using namespace std;
int main()
{
	long n;
	cin >> n;
	while (1 != n) {
		for (int i = 2;i <= n;i++) {
			if (0 == n%i) {
				n /= i;
				cout << i << " ";
				break;
			}
		}
	}
	return 0;
}