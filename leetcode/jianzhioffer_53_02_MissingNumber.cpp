//https://www.acwing.com/problem/content/description/64/
class Solution {
public:
	int getMissingNumber(vector<int>& num)
	{
		if (num.empty())
		{
			return 0;
		}
		int begin = 0;
		int end = num.size() - 1;
		while (begin <= end)
		{
			int mid = (end - begin) / 2 + begin;//用右移有问题
			if (num[mid] != mid)
			{
				if (mid == 0 || num[mid - 1] == mid - 1)
				{
					return mid;
				}
				end = mid - 1;

			}
			else
			{
				begin = mid + 1;
			}
		}
		if (begin == num.size())
		{
			return num.size();
		}
		return -1;
	}
};