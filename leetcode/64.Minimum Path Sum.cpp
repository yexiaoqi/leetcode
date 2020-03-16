//同剑指offer47几乎一致
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (i<1 && j >= 1)
				{
					dp[i][j] = dp[i][j - 1] + grid[i][j];
				}
				else if (j<1 && i >= 1)
				{
					dp[i][j] = dp[i - 1][j] + grid[i][j];
				}
				else if (i >= 1 || j >= 1)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

//空间优化，一维数组
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n, 0);//注意初始化为n大小
		dp[0] = grid[0][0];
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (i<1 && j >= 1)
				{
					dp[j] = dp[j - 1] + grid[i][j];
				}
				else if (j<1 && i >= 1)
				{
					dp[j] = dp[j] + grid[i][j];
				}
				else if (i >= 1 || j >= 1)
				{
					dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
				}
			}
		}
		return dp.back();
	}
};