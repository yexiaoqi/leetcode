//自己想出，一遍ac
//https://www.acwing.com/problem/content/65/
class Solution {
public:
	int getNumberSameAsIndex(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (end - begin) / 2 + begin;
			if (mid == nums[mid])
			{
				return mid;
			}
			else if (nums[mid]>mid)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
};