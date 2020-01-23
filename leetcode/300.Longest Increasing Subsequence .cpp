//方法一，o(n^2)解法
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp(nums.size(), 1);
		int maxres = 1;
		for (int i = 1; i<nums.size(); ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (nums[j]<nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (maxres<dp[i])
			{
				maxres = dp[i];
			}
		}
		return maxres;
	}
};

//o(nlogn)解法
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		for (int i = 0; i<nums.size(); ++i)
		{
			int left = 0, right = dp.size();
			while (left<right)//对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字
			{
				int mid = (left + right) / 2;
				if (dp[mid]<nums[i])
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			if (right == dp.size())//如果right遍历到了最后，那么说明这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//如果存在，则将这个数字更新为当前遍历到的数字
			}
		}
		return dp.size();
	}
};