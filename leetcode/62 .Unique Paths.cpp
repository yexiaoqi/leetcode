//二维数组
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m<1 || n<1)
		{
			return 0;
		}
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i<n; ++i)
		{
			dp[0][i] = 1;
		}
		for (int i = 0; i<m; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 1; i<m; ++i)
		{
			for (int j = 1; j<n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};

//一维数组
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m<1 || n<1)
		{
			return 0;
		}
		//vector<vector<int>> dp(m,vector<int>(n,0));
		vector<int> dp(n, 0);
		for (int i = 0; i<n; ++i)
		{
			//dp[0][i]=1;
			dp[i] = 1;
		}
		// for(int i=0;i<m;++i)
		// {
		//     dp[i][0]=1;
		// }
		for (int i = 1; i<m; ++i)
		{
			for (int j = 1; j<n; ++j)
			{
				//dp[i][j]=dp[i-1][j]+dp[i][j-1];
				dp[j] = dp[j] + dp[j - 1];
			}
		}
		//return dp[m-1][n-1];
		return dp[n - 1];
	}
};



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