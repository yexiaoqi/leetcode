//ͬleetcode 518
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		if (n == 0)
		{
			return amount == 0 ? 1 : 0;
		}
		vector<int> dp(amount + 1, 0);
		for (int i = 0; i*coins[0] <= amount; ++i)
		{
			dp[i*coins[0]] = 1;
		}
		for (int i = 1; i<n; ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				if (j >= coins[i])
				{
					dp[j] += dp[j - coins[i]];
				}
			}
		}
		return dp.back();
	}
};