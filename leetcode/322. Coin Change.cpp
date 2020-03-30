class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp;
		for (int i = 0; i <= amount; ++i)
		{
			dp.push_back(-1);
		}
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			for (int j = 0; j<coins.size(); ++j)
			{
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
				{
					if (dp[i] == -1 || dp[i]>dp[i - coins[j]] + 1)
					{
						dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		return dp[amount];
	}
};

//复习，自己做出
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			for (int j = 0; j<coins.size(); ++j)
			{
				if (i >= coins[j] && dp[i - coins[j]] != -1)
				{
					if (dp[i] == -1 || dp[i]>dp[i - coins[j]] + 1)
					{
						dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		return dp.back();
	}
};


//背包问题模板
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<long> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i<coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount]<INT_MAX ? dp[amount] : -1;
	}
};


//二维
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() == 0 || amount <= 0)
		{
			return 0;
		}
		int m = coins.size();
		vector<vector<long>> dp(m + 1, vector<long>(amount + 1, INT_MAX));
		dp[0][0] = 0;
		for (int i = 0; i <= m; ++i)
		{
			dp[i][0] = 0;
		}
		// for(int j=1;j<=amount;++j)
		// {
		//     dp[0][j]=0;
		// }
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 0; j <= amount; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= coins[i - 1])
				{
					dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
				}
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
		return dp[m][amount] >= INT_MAX ? -1 : dp[m][amount];
	}
};


//二维简化为一维数组
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() == 0 || amount <= 0)
		{
			return 0;
		}
		int m = coins.size();
		vector<long> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = coins[i - 1]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
			}
		}
		return dp[amount] >= INT_MAX ? -1 : dp[amount];
	}
};