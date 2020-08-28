//ͬleetcode75
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		int i = 0;
		while (i <= end)
		{
			if (nums[i] == 0)
			{
				swap(nums[i++], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[end--]);
			}
			else
			{
				++i;
			}
		}
	}
};