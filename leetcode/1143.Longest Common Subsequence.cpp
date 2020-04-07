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
		int tmp = 0, now = 0;//用tmp来表示左上角
		for (int i = 0; i<m; ++i)
		{
			//tmp = 0;//用tmp来表示左上角
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

//简化版本 （m+1）*（n+1）
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		if (m == 0 || n == 0)
		{
			return 0;
		}
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (text1[i - 1] == text2[j - 1])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		return dp[m][n];
	}
};



//简化版本
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		if (m == 0 || n == 0)
		{
			return 0;
		}
		//vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		vector<int> dp(n + 1, 0);
		int tmp = 0, cur = 0;
		for (int i = 1; i <= m; ++i)
		{
			tmp = 0;
			for (int j = 1; j <= n; ++j)
			{
				cur = dp[j];
				//dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				dp[j] = max(dp[j], dp[j - 1]);
				if (text1[i - 1] == text2[j - 1])
				{
					//dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					dp[j] = max(dp[j], tmp + 1);
				}
				tmp = cur;
			}
		}
		//return dp[m][n];
		return dp[n];
	}
};



//输出一个最长子序列
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		if (m == 0 || n == 0)
		{
			return 0;
		}
		vector<int> dp(n + 1, 0);
		string resstr;
		int tmp = 0, cur = 0;
		vector<vector<pair<int, int>>> pos(m + 1, vector<pair<int, int>>(n + 1, pair<int, int>()));
		for (int i = 1; i <= m; ++i)
		{
			tmp = 0;
			for (int j = 1; j <= n; ++j)
			{
				cur = dp[j];
				if (dp[j] > dp[j - 1])
				{
					pos[i][j] = make_pair(i - 1, j);
				}
				else
				{
					pos[i][j] = make_pair(i, j - 1);
				}
				dp[j] = max(dp[j], dp[j - 1]);

				if (text1[i - 1] == text2[j - 1])
				{
					if (dp[j]<tmp + 1)
					{
						pos[i][j] = make_pair(i - 1, j - 1);
					}
					dp[j] = max(dp[j], tmp + 1);

				}
				tmp = cur;
			}
		}
		// for(int i=1;i<=m;++i)
		// {
		//     for(int j=1;j<=n;++j)
		//     {
		//         if(pos[i][j].first==i-1&&pos[i][j].second==j-1)
		//         {
		//             resstr+=text2[j-1];
		//         }
		//     }
		// }


		// for(int i=0;i<=m;i++){
		//     for(int j=0;j<=n;j++){
		//         cout<<i<<","<<j<<"-->"<<pos[i][j].first<<" "<<pos[i][j].second<<endl;
		//     }
		// }

		int i = m, j = n;
		//while(!(pos[i][j].first==0&&pos[i][j].second==0))
		while (!(i == 0 && j == 0))
		{
			//cout<<pos[i][j].first<<" "<<pos[i][j].second<<", "<<i<<" "<<j<<endl;
			if(pos[i][j].first==i-1&&pos[i][j].second==j-1)
			//if ((i == pos[i][j].first + 1) && (j == pos[i][j].second + 1))
			{
				str.insert(0, 1, text2[j - 1]);//string &insert(int p0, int n, char c);//在p0处插入n个字符c
				//resstr += text2[j - 1];
			}
			int tmp = pos[i][j].first;
			j = pos[i][j].second;
			i = tmp;
		}
		//reverse(resstr.begin(), resstr.end());
		cout << resstr;
		return dp[n];
	}
};