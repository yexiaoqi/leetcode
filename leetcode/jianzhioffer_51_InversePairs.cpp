class Solution {
public:
	int InversePairs(vector<int> data)
	{
		if (data.size() == 0)
		{
			return 0;
		}
		vector<int> copy(data.begin(), data.end());
		int res = Inverse(data, copy, 0, data.size() - 1);
		return res;
	}
	int  Inverse(vector<int> &data, vector<int> &copy, int start, int end)
	{
		if (start == end)
		{
			return 0;
		}
		int mid = (end + start) / 2;
		int left = Inverse(data, copy, start, mid) % 1000000007;
		int right = Inverse(data, copy, mid + 1, end) % 1000000007;
		int cnt = 0;
		int i = mid;
		int j = end;
		int loccopy = end;
		while (i >= start&&j>mid)
		{
			if (data[i]>data[j])
			{
				copy[loccopy--] = data[i--];
				cnt += j - mid;
				if (cnt >= 1000000007)
				{
					cnt %= 1000000007;
				}
			}
			else
			{
				copy[loccopy--] = data[j--];
			}
		}
		for (; i >= start; i--)
		{
			copy[loccopy--] = data[i];
		}
		for (; j>mid; j--)
		{
			copy[loccopy--] = data[j];
		}
		for (int m = start; m <= end; ++m)
		{
			data[m] = copy[m];
		}//注意这里赋值给data
		return (left + right + cnt) % 1000000007;
	}
};
