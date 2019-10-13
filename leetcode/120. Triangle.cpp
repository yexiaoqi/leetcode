//方法1
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		if (triangle.size() == 0)
		{
			return 0;
		}
		//int size=triangle.size();
		vector<vector<int>> dp;
		for (int i = 0; i<triangle.size(); ++i)
		{
			dp.push_back(vector<int>());//注意vector<int>()要有();
			for (int j = 0; j<triangle[i].size(); ++j)
			{
				dp[i].push_back(0);
			}
		}
		for (int i = 0; i<dp.size(); ++i)
		{
			dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
		}
		for (int i = int(dp.size()) - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}
};

//简化版
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {


		 if(triangle.size()==0)
		{
		return 0;
		}
		vector<int> dp(triangle.back());
		for(int i=triangle.size()-2;i>=0;i--)
		{
		for(int j=0;j<=i;j++)
		{
		dp[j]=std::min(dp[j],dp[j+1])+triangle[i][j];
		}
		}
		return dp[0];
	}
};