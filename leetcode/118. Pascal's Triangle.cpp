//自己做出
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows <= 0)
		{
			return vector<vector<int>>();
		}
		vector<vector<int>> dp(numRows, vector<int>(1, 1));
		for (int i = 1; i<numRows; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				dp[i].push_back(dp[i - 1][j - 1]);
				if (j<i)
				{
					dp[i][j] += dp[i - 1][j];
				}
			}
		}
		return dp;
	}
};

//
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows <= 0)
		{
			return vector<vector<int>>();
		}
		vector<vector<int>> dp(numRows, vector<int>());
		for (int i = 0; i<numRows; ++i)
		{
			dp[i].resize(i + 1, 1);
			for (int j = 1; j<i; ++j)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		return dp;
	}
};