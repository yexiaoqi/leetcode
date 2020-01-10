class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int max_arr = dp[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			if (max_arr<dp[i])
			{
				max_arr = dp[i];
			}
		}
		return max_arr;

	}
};

//¸´Ï°£¬Ò»±éac
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			if (res<dp[i])
			{
				res = dp[i];
			}
		}
		return res;
	}
};