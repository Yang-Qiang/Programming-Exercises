class Solution {
public:
	/**
	* 获得两个整形二进制表达位数不同的数量
	*
	* @param m 整数m
	* @param n 整数n
	* @return 整型
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

//两个整数异或便可获得这两个整数的二进制表达式位数不同的数量