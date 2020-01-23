//Í¬½£Ö¸offer 3_02
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 1, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			int cnt = CountTimes(nums, begin, mid);
			if (begin == end)
			{
				if (cnt>1)
				{
					return begin;
				}
				else
				{
					return -1;
				}
			}
			if (cnt>mid - begin + 1)
			{
				end = mid;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
	int CountTimes(vector<int>&nums, int begin, int mid)
	{
		int cnt = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] >= begin&&nums[i] <= mid)
			{
				++cnt;
			}
		}
		return cnt;
	}
};