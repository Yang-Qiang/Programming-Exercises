class Solution {
public:
	/**
	* ����������ζ����Ʊ��λ����ͬ������
	*
	* @param m ����m
	* @param n ����n
	* @return ����
	*/
	int countBitDiff(int m, int n) {
		int temp = 0;
		int count = 0;
		temp = m^n;
		while (temp != 0)
		{
			count++;
			temp = temp&(temp - 1);
		}
		return count;
	}
};

//������������ɻ�������������Ķ����Ʊ��ʽλ����ͬ������