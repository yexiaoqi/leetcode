//�Լ��Ľⷨ�����ռ�
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


//����ͨ����
// ���⻹���ռ��ˣ����k����n / 2�Ļ���������ÿ�춼�ڽ��ף����ڲ����ƽ��״���������������ò����ƽ��״����Ĵ���
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
		if (k>n / 2)//���⻹���ռ��ˣ����k����n/2�Ļ���������ÿ�춼�ڽ��ף����ڲ����ƽ��״���������������ò����ƽ��״����Ĵ���
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