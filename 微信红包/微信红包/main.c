class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		if (0 == n) return 0;
		int count = 1;
		int temp = gifts[0];
		for (int i = 1;i<n;i++) {
			if (0 == count) {
				temp = gifts[i];
				count++;
			}
			else if (temp == gifts[i])
				count++;
			else count--;
		}
		count = 0;
		for (int i = 0;i<n;i++)
			if (temp == gifts[i])
				count++;
		if (count>n >> 2)	return temp;
		else return 0;
	}
};