class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		if (text1.empty() || text2.empty())
		{
			return 0;
		}
		int m = text1.size(), n = text2.size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (i == 0 && j == 0)
				{
					dp[0][0] = text1[0] == text2[0] ? 1 : 0;
				}
				else if (i == 0 && j != 0)
				{
					dp[0][j] = max(dp[0][j - 1], text1[0] == text2[j] ? 1 : 0);
				}
				else if (j == 0 && i != 0)
				{
					dp[i][0] = max(dp[i - 1][0], text1[i] == text2[0] ? 1 : 0);
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					if (text1[i] == text2[j])
					{
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};


//一维数组优化
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		if (text1.empty() || text2.empty())
		{
			return 0;
		}
		int m = text1.size(), n = text2.size();
		// vector<vector<int>> dp(m,vector<int>(n,0));
		vector<int> dp(n, 0);
		int tmp = 0, now = 0;
		for (int i = 0; i<m; ++i)
		{
			tmp = 0;//用tmp来表示左上角
			for (int j = 0; j<n; ++j)
			{
				now = dp[j];
				if (i == 0 && j == 0)
				{
					//dp[0][0]=text1[0]==text2[0]?1:0;
					dp[0] = text1[0] == text2[0] ? 1 : 0;
				}
				else if (i == 0 && j != 0)
				{
					//dp[0][j]=max(dp[0][j-1],text1[0]==text2[j]?1:0);
					dp[j] = max(dp[j - 1], text1[0] == text2[j] ? 1 : 0);
				}
				else if (j == 0 && i != 0)
				{
					//dp[i][0]=max(dp[i-1][0],text1[i]==text2[0]?1:0);
					dp[0] = max(dp[0], text1[i] == text2[0] ? 1 : 0);
				}
				else
				{
					//dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					dp[j] = max(dp[j], dp[j - 1]);
					if (text1[i] == text2[j])
					{
						//dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
						dp[j] = max(dp[j], tmp + 1);
					}
				}
				tmp = now;//tmp不是更新后的dp[j]，所以要在上面就now=dp[j];
			}
		}
		// return dp[m-1][n-1];
		return dp[n - 1];
	}
};