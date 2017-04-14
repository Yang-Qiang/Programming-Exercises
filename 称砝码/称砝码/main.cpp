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

//����˼·�����Ȱѵ�N-1���������е������������飬Ȼ���N���������η���1,2,3......j����ÿ������iʱ����֮ǰN-1������������
//���Ѵ��ڣ��򲻴��룬�������