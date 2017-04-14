#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> value;
	while (cin >> n) {
		if (n < 1)	return 0;
		int *weight = new int[n];
		int *nums = new int[n];
		int i = 0;
		for (i = 0;i < n;i++) {
			cin >> weight[i];
		}
		for (i = 0;i < n;i++) {
			cin >> nums[i];
		}
		int weights = 0;
		for (i = 0;i <= nums[0];i++) {
			weights = i*weight[0];
			value.push_back(weights);
		}
		for (i = 1;i < n;i++) {
			for (int j = 1;j <= nums[i];j++) {
				int size = value.size();
				for (int m = 0;m < size;m++) {
					weights = value[m] + j*weight[i];
					if (find(value.begin(), value.end(), weights) == value.end()) {
						value.push_back(weights);
					}
				}
			}
		}
		cout << value.size() << endl;
		free(weight);
		free(nums);

	}
	return 0;
}

//基本思路就是先把第N-1个砝码所有的重量存入数组，然后第N个砝码依次放入1,2,3......j个。每当放入i时，与之前N-1存入的重量相加
//若已存在，则不存入，否则存入