class Solution {
public:
	void probability(int num)
	{
		if (num < 1)
		{
			return;
		}//注意特殊情况
		vector<vector<int>> dp(2, vector<int>(g_maxvalue*num + 1, 0));//注意初始化
		int flag = 0;
		for (int i = 1; i <= g_maxvalue; ++i)
		{
			dp[flag][i] = 1;
		}
		for (int k = 2; k <= num; ++k)
		{
			for (int i = k; i <= g_maxvalue*k; ++i)
			{
				for (int j = 1; j < i&&j <= g_maxvalue; ++j)
				{
					dp[1 - flag][i] += dp[flag][i - j];
				}
			}
			flag = 1 - flag;
		}
		int total = pow(g_maxvalue, num);
		for (int i = num; i <= g_maxvalue*num; ++i)
		{
			double ratio = (double)dp[flag][i] / total;
			cout << i << " " << ratio << endl;

		}
	}
private:
	int g_maxvalue = 6;
};