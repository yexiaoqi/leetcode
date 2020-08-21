//aliniuke_FindMinddiff是该题升级版
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += nums[i];
		}
		if (sum % 2 != 0)
		{
			return false;
		}
		int halfsum = sum / 2;
		vector<int> dp(halfsum + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = halfsum; j >= nums[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		if (dp.back() == halfsum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};