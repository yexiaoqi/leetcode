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




//复习，按照标准mergesort
class Solution {
public:
	int InversePairs(vector<int> data)
	{
		if (data.size() == 0)
		{
			return 0;
		}
		vector<int> tmp(data.begin(), data.end());
		int res = mergesort(data, 0, data.size() - 1, tmp);
		return res;
	}
	int  mergesort(vector<int> &arr, int begin, int end, vector<int> &tmp)//必须有&tmp，不加引用时间过大
	{
		if (begin == end)
		{
			return 0;
		}
		int mid = (begin + end) / 2;
		int left = mergesort(arr, begin, mid, tmp) % 1000000007;
		int right = mergesort(arr, mid + 1, end, tmp) % 1000000007;
		int cnt = 0;
		cnt = mergearray(arr, begin, end, mid, tmp);
		return (left + right + cnt) % 1000000007;
	}
	int mergearray(vector<int> &arr, int begin, int end, int mid, vector<int> &tmp)
	{
		int cnt = 0;
		int i = mid;
		int j = end;
		int k = end;
		while (i >= begin&&j>mid)
		{
			if (arr[i]>arr[j])
			{
				tmp[k--] = arr[i--];
				cnt += j - mid;
				if (cnt >= 1000000007)//这里的判断不能少，如果只在后面判断太晚了
				{
					cnt %= 1000000007;
				}
			}
			else
			{
				tmp[k--] = arr[j--];
			}
		}

		while (i >= begin)
		{
			tmp[k--] = arr[i--];
		}
		while (j>mid)
		{
			tmp[k--] = arr[j--];
		}
		for (int m = begin; m <= end; ++m)
		{
			arr[m] = tmp[m];
		}//注意这里赋值给data
		return cnt % 1000000007;
	}

};
