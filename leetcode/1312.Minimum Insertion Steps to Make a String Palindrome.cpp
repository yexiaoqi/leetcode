//本题属于516. 最长回文子序列的子题，求的就是不为最长回文子序列的字符个数，所以我们只需要用字符串长度减去最长回文子序列的长度就是最少插入次数了。
class Solution {
public:
	int minInsertions(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i)
		{
			dp[i][i] = 1;
			for (int j = i + 1; j<n; ++j)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return n - dp[0][n - 1];
	}
};