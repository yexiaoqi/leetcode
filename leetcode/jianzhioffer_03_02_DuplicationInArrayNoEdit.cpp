class Solution {
public:
	int finddup(vector<int> num, int n)
	{
		if (num.size() == 0 || n<1)
		{
			return -1;
		}
		int start = 1;
		int end = num.size() - 1;
		while (start <= end)
		{

			int mid = (end - start) / 2 + start;
			int cnt = counttimes(num, start, mid);
			if (start == end)
			{
				if (cnt > 1)
				{
					return start;
				}
				else
				{
					break;
				}
			}
			if (cnt > (mid - start + 1))
			{
				end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}
		return -1;
	}
	int counttimes(vector<int> num, int start, int mid)
	{
		int cnt = 0;
		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] >= start&&num[i] <= mid)
			{
				++cnt;
			}
		}
		return cnt;
	}
};