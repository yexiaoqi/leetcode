//o(n)空间复杂度解法，寻找映射关系
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0)
		{
			return;
		}
		vector<int> t = nums;
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[(i + k) % (nums.size())] = t[i];
		}
		return;
	}
};

//o(1)空间复杂度解法
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
		{
			return;
		}
		k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};