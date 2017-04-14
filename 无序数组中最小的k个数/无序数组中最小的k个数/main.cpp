//�����ÿ��������˼���ҵ���KС��Ԫ�أ�Ȼ�����ԭ�����������С�ڻ���ڸ�Ԫ�ص�ֵ

class KthNumbers {
public:

	//��������arr arr[0],arr[1].......arr[i] i<=end����quickFind��������ģ���i==currentʱ����arr[i];
	int quickFind(vector<int>&arr, int start, int end, int k)
	{
		if (start == end)
		{
			return arr[start];
		}

		int current = start;
		int left = start + 1;
		int right = end;
		while (left <= right)
		{
			while ((left <= right) && (arr[right] >= arr[current]))
			{
				right--;
			}

			if (left <= right)
			{
				int tmp = arr[right];
				arr[right] = arr[current];
				arr[current] = tmp;
				current = right;
			}

			while ((left <= right) && arr[left] <= arr[current])
			{
				left++;
			}

			if (left <= right)
			{
				int temp = arr[left];
				arr[left] = arr[current];
				arr[current] = temp;
				current = left;
			}
		}

		if (current < k)
		{
			return quickFind(arr, current + 1, end, k);
		}

		if (current > k)
		{
			return quickFind(arr, start, current - 1, k);
		}

		return arr[current];
	}



	vector<int> findKthNumbers(vector<int> A, int n, int k)
	{
		// write code here
		vector<int> res;
		if (k > n || n < 1) {
			return res;
		}
		res.assign(A.begin(), A.end());
		int val = quickFind(res, 0, n - 1, k - 1);
		res.clear();
		for (unsigned long int i = 0; i < A.size(); i++)
		{
			if (A[i] <= val)
			{
				res.push_back(A[i]);
			}
		}
		return res;
	}
};