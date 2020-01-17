class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		if (nums.size() == 0)
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			return nums[0];
		}
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		int res = max(dp[0], dp[1]);
		for (int i = 2; i<nums.size(); ++i)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			if (dp[i]>res)
			{
				res = dp[i];
			}
		}
		return res;
	}
};


//¸´Ï°
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			if (i<2)
			{
				dp[i] = max(dp[0], nums[1]);
			}
			else//Òª¼Óelse
			{
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			}

		}
		return dp.back();
	}
};