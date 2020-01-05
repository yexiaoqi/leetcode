//��ˢ������վ
//https://www.acwing.com/problem/content/56/
class Solution {
public:
	int getMaxValue(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		vector<int> dp(grid[0].size(), 0);
		//int left = 0, up = 0;//�����������ʼ����������i=1��j=0��ʱleft��Ӧ����0��ȴ��ֵ
		dp[0] = grid[0][0];
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				int left = 0, up = 0;
				if (i > 0)
				{
					up = dp[j];
				}
				if (j > 0)
				{
					left = dp[j - 1];
				}
				dp[j] = max(left, up) + grid[i][j];
			}
		}
		return dp.back();
	}
};