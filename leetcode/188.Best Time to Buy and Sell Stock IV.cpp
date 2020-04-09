//自己的解法，超空间
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		int n = prices.size();
		if (k <= 0 || n <= 1)
		{
			return 0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
		for (int i = 0; i<n; ++i)
		{
			for (int m = 1; m <= k; ++m)
			{
				if (i == 0)
				{
					dp[i][m][0] = 0;
					dp[i][m][1] = -prices[i];
				}
				else
				{
					dp[i][m][0] = max(dp[i - 1][m][0], dp[i - 1][m][1] + prices[i]);
					dp[i][m][1] = max(dp[i - 1][m][1], dp[i - 1][m - 1][0] - prices[i]);
				}
			}
		}
		return dp[n - 1][k][0];
	}
};


//可以通过的
// 这题还卡空间了，如果k大于n / 2的话，最多就是每天都在交易，等于不限制交易次数，这种情况调用不限制交易次数的代码
class Solution {
public:
	int maxProfit2(vector<int>& prices)
	{
		int res = 0;
		for (int i = 1; i<prices.size(); ++i)
		{
			if (prices[i]>prices[i - 1])
			{
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}
	int maxProfit(int k, vector<int>& prices) {
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		int n = prices.size();
		if (k <= 0 || n <= 1)
		{
			return 0;
		}
		if (k>n / 2)//这题还卡空间了，如果k大于n/2的话，最多就是每天都在交易，等于不限制交易次数，这种情况调用不限制交易次数的代码
		{
			return maxProfit2(prices);
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
		for (int i = 0; i<n; ++i)
		{
			for (int m = 1; m <= k; ++m)
			{
				if (i == 0)
				{
					dp[i][m][0] = 0;
					dp[i][m][1] = -prices[i];
				}
				else
				{
					dp[i][m][0] = max(dp[i - 1][m][0], dp[i - 1][m][1] + prices[i]);
					dp[i][m][1] = max(dp[i - 1][m][1], dp[i - 1][m - 1][0] - prices[i]);
				}
			}
		}
		return dp[n - 1][k][0];
	}
};