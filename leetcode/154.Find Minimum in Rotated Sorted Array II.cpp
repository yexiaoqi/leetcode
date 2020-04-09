//Í¬½£Ö¸offer11
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 0, end = nums.size() - 1;
		int res = INT_MAX;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (res>nums[mid])
			{
				res = nums[mid];
			}
			if (nums[mid]<nums[end])
			{
				end = mid - 1;
			}
			else if (nums[mid] == nums[end])
			{
				--end;
			}
			else
			{
				res = nums[begin];
				begin = mid + 1;
			}
		}
		return res;
	}
};