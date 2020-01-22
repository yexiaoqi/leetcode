class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res1(nums.size(), 1);
		vector<int> res2(nums.size(), 1);
		vector<int> res(nums.size(), 1);
		for (int i = 1; i<nums.size(); ++i)
		{
			res1[i] = res1[i - 1] * nums[i - 1];
		}
		for (int i = nums.size() - 2; i >= 0; --i)//注意是nums.size()-2不是-1，nums.size()-1是1
		{
			res2[i] = res2[i + 1] * nums[i + 1];
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			res[i] = res1[i] * res2[i];
		}
		return res;
	}
};