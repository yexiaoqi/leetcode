//要用两个 dp 数组，其中 f[i] 表示子数组[0, i] 范围内并且一定包含 nums[i] 数字的最大子数组乘积，
//g[i] 表示子数组[0, i] 范围内并且一定包含 nums[i] 数字的最小子数组乘积，
//初始化时 f[0] 和 g[0] 都初始化为 nums[0]，其余都初始化为0。那么从数组的第二个数字开始遍历，
//那么此时的最大值和最小值只会在这三个数字之间产生，即 f[i - 1] * nums[i]，g[i - 1] * nums[i]，和 nums[i]。
//所以用三者中的最大值来更新 f[i]，用最小值来更新 g[i]，然后用 f[i] 来更新结果 res 即可，
//由于最终的结果不一定会包括 nums[n - 1] 这个数字，所以 f[n - 1] 不一定是最终解，不断更新的结果 res 才是，
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