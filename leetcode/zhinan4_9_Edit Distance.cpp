class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		//vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		vector<int> dp(n + 1, 0);
		int tmp = 0, now = 0;
		//for(int i=1;i<=m;++i)
		//{
		//dp[i][0]=i;
		// dp[0]=i;
		//}
		for (int i = 1; i <= n; ++i)
		{
			//dp[0][i]=i;
			dp[i] = i;
		}
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				now = dp[j];
				//int one=dp[i-1][j]+1,two=dp[i][j-1]+1,three=dp[i-1][j-1];
				int one = dp[j] + 1, two = dp[j - 1] + 1, three = tmp;
				if (word1[i - 1] != word2[j - 1])
				{
					++three;
				}
				//dp[i][j]=min(min(one,two),three);
				dp[j] = min(min(one, two), three);
				tmp = now;
			}
		}
		//return dp[m][n];
		return dp[n];
	}
};