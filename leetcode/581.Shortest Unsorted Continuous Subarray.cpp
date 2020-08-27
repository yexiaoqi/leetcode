//时间复杂度o(nlogn),空间复杂度o(n)
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		int n = nums.size();
		int i = 0, j = n - 1;
		while (i<n)
		{
			if (tmp[i] != nums[i])
			{
				break;
			}
			else
			{
				++i;
			}
		}
		while (j>i)
		{
			if (tmp[j] != nums[j])
			{
				break;
			}
			else
			{
				--j;
			}
		}
		return j - i + 1;
	}
};

//时间复杂度o(n),空间复杂度o(1)
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size(), start = -1, end = -2;
		int mn = nums[n - 1], mx = nums[0];
		for (int i = 1; i<n; ++i)
		{
			mx = max(mx, nums[i]);
			mn = min(mn, nums[n - 1 - i]);
			if (mn<nums[n - 1 - i])
			{
				start = n - 1 - i;
			}
			if (mx>nums[i])
			{
				end = i;
			}
		}
		return end - start + 1;
	}
};