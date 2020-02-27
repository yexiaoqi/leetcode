class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		if (nums.size()<2)
		{
			return res;
		}
		int begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int sum = nums[begin] + nums[end];
			if (sum == target)
			{
				res[0] = begin + 1;
				res[1] = end + 1;
				return res;
			}
			else if (sum<target)
			{
				++begin;
			}
			else
			{
				--end;
			}
		}
		return res;
	}
};