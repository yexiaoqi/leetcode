class Solution {
public:
	int maxProfit(vector<int>& prices) {
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
};


//股票问题通用方法
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		//here k=INT_MAX,k与k-1可以看成相等
		//so dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
		//dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices)
		vector<int> dp(2, 0);
		if (prices.size() == 0)
		{
			return 0;
		}
		dp[1] = INT_MIN;
		for (int i = 0; i<prices.size(); ++i)
		{
			int tmp = max(dp[0], dp[1] + prices[i]);
			dp[1] = max(dp[1], dp[0] - prices[i]);
			dp[0] = tmp;
		}
		return dp[0];
	}
};