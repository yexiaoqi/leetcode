//ͬleetcode174class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size() == 0 || dungeon[0].size() == 0)
		{
			return -1;
		}
		int m = dungeon.size(), n = dungeon[0].size();
		//vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));//ע������min(dp[i][j+1],dp[i+1][j])������Ҫ��ʼ��ΪINT_MAX
		vector<int> dp(n + 1, INT_MAX);
		//dp[m][n-1]=1;
		dp[n - 1] = 1;
		//dp[m-1][n]=1;
		//dp[n]=1;//ע�ⲻӦ����dp[n]=1;���������ʼ����dp[n]��С
		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				//dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j]);
				dp[j] = max(1, min(dp[j + 1], dp[j]) - dungeon[i][j]);
			}
		}
		//return dp[0][0];
		return dp[0];
	}
};