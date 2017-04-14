class Solution {
public:
	int getUpMedian(vector<int> arr1, vector<int> arr2) {

		if (arr1.size() <= 0 || arr2.size() <= 0 || arr1.size() != arr2.size())
			return 0;
		int L1 = 0;
		int R1 = arr1.size() - 1;
		int L2 = 0;
		int R2 = arr2.size() - 1;
		while (L1 < R1 && L2 < R2)
		{
			int mid1 = (R1 + L1) / 2;
			int mid2 = (R2 + L2) / 2;

			if (arr1[mid1] == arr2[mid2])
				return arr1[mid1];

			if (arr1[mid1] <arr2[mid2])
			{
				mid1 = ((R1 + L1) % 2 == 0) ? mid1 : (mid1 + 1);
				L1 = mid1;
				R2 = mid2;
			}
			else
			{
				mid2 = ((R2 + L2) % 2 == 0) ? mid2 : (mid2 + 1);
				R1 = mid1;
				L2 = mid2;
			}
		}
		return (arr1[L1] > arr2[L2]) ? arr2[L2] : arr1[L1];
	}
};