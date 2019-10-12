class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		int index = -1;
		while (index == -1)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[mid]<target)
			{
				if (mid == nums.size() - 1 || nums[mid + 1]>target)
				{
					index = mid + 1;
				}
				begin = mid + 1;
			}
			else
			{
				if (mid == 0 || nums[mid - 1]<target)
				{
					index = mid;
				}
				end = mid - 1;
			}
		}
		return index;
	}
};