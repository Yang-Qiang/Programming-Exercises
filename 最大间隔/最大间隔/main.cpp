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


//����˼·  ������ԭ������������Ȼ����ɾ��һ�����󣬸�����ǰ���������ļ������Сֵtemp�����Ƚ�����������
//1.��ԭ��������������ɾ��һ�����󣬸�����ǰ����������ֵ����Сֵ��˵�������ֵ����Сֵ�Ǹ�max������temp

