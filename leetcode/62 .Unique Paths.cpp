//自己做出，一遍ac
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m<1 || n<1)
		{
			return -1;
		}
		vector<vector<int>> dp(2, vector<int>(m, 1));
		int flag = 0;
		while (--n)
		{
			for (int i = 0; i<m; ++i)
			{
				if (i >= 1)
				{
					dp[1 - flag][i] = dp[flag][i] + dp[1 - flag][i - 1];
				}
			}
			flag = 1 - flag;
		}
		return dp[flag][m - 1];
	}
};