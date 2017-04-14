#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>num;
	int n;
	int a;
	while (cin >> n) {
		int i = 0;
		for (i = 0;i < n;i++) {
			cin >> a;
			num.push_back(a);
	}
		int max = 0;
		if (n >= 2) {
			max = num[1] - num[0];
		}
		for (i = 2;i < n;i++) {
			max = max >(num[i] - num[i - 1]) ? max : (num[i] - num[i - 1]);
		}
		int temp = num[2] - num[0];
		for (i = 2;i < n - 1;i++) {
			temp = temp < (num[i + 1] - num[i - 1]) ? temp : (num[i + 1] - num[i - 1]);
		}
		cout<<(max > temp ? max : temp)<<endl;
	}
	return 0;
}


//解题思路  首先求原数组的最大间隔，然后求删除一个数后，该数的前后两个数的间隔的最小值temp，最后比较这两个数。
//1.若原数组的最大间隔大于删除一个数后，该数的前后两个数的值得最小值，说明最大间隔值得最小值是该max否则是temp

