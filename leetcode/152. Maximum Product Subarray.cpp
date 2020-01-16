class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<vector<int>> dp(2, (vector<int>(nums.size(), 0)));
		dp[0][0] = nums[0];
		dp[1][0] = nums[0];
		int res = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			dp[0][i] = max(max(nums[i], dp[1][i - 1] * nums[i]), dp[0][i - 1] * nums[i]);
			dp[1][i] = min(min(nums[i], dp[1][i - 1] * nums[i]), dp[0][i - 1] * nums[i]);
			if (res<dp[0][i])
			{
				res = dp[0][i];
			}
		}
		return res;
	}
};