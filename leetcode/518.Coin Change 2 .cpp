class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (coins.size() == 0)
		{
			return amount == 0 ? 1 : 0;
		}
		int m = coins.size();
		vector<vector<int>> dp(m, vector<int>(amount + 1, 0));
		for (int i = 0; i<coins.size(); ++i)
		{
			dp[i][0] = 1;
			for (int j = 1; j <= amount; ++j)
			{
				if (i == 0 && j%coins[i] == 0)
				{
					dp[i][j] = 1;//如果只有一种硬币，那么只有它的整数倍才能构成
				}
				if (i >= 1)
				{
					dp[i][j] = dp[i - 1][j];//不用这一种硬币
					if (j >= coins[i])
					{
						dp[i][j] += dp[i][j - coins[i]];//加一枚这种硬币
					}
				}
			}
		}
		return dp[m - 1][amount];
	}
};


//这样的二维数组更加清晰，dp双重循环都从1，1开始
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (coins.size() == 0)
		{
			return amount == 0 ? 1 : 0;
		}
		int m = coins.size();
		vector<vector<int>> dp(m, vector<int>(amount + 1, 0));
		for (int i = 0; i<coins.size(); ++i)
		{
			dp[i][0] = 1;
		}
		for (int j = 1; coins[0] * j <= amount; ++j)
		{
			dp[0][coins[0] * j] = 1;//如果只有一种硬币，那么只有它的整数倍才能构成
		}
		for (int i = 1; i<coins.size(); ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				dp[i][j] = dp[i - 1][j];//不用这一种硬币
				if (j >= coins[i])
				{
					dp[i][j] += dp[i][j - coins[i]];//加一枚这种硬币
				}
			}
		}
		return dp[m - 1][amount];
	}
};


//优化为一维数组
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (coins.size() == 0)
		{
			return amount == 0 ? 1 : 0;
		}
		int m = coins.size();
		//vector<vector<int>> dp(m,vector<int>(amount+1,0));
		vector<int> dp(amount + 1, 0);
		for (int i = 0; i<coins.size(); ++i)
		{
			//dp[i][0]=1;
			dp[0] = 1;
			for (int j = 1; j <= amount; ++j)
			{
				if (i == 0 && j%coins[i] == 0)
				{
					//dp[i][j]=1;
					dp[j] = 1;
				}
				if (i >= 1)
				{
					//dp[i][j]=dp[i-1][j];
					if (j >= coins[i])
					{
						//dp[i][j]+=dp[i][j-coins[i]];
						dp[j] += dp[j - coins[i]];
					}
				}
			}
		}
		//return dp[m-1][amount];
		return dp[amount];
	}
};


//一维数组清晰版
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (coins.size() == 0)
		{
			return amount == 0 ? 1 : 0;
		}
		int m = coins.size();
		//vector<vector<int>> dp(m, vector<int>(amount + 1, 0));
		vector<int> dp(amount + 1, 0);
		// for (int i = 0; i<coins.size(); ++i)
		// {
		//     dp[i][0] = 1;
		// }
		dp[0] = 1;
		for (int j = 1; coins[0] * j <= amount; ++j)
		{
			//dp[0][coins[0]*j]=1;//如果只有一种硬币，那么只有它的整数倍才能构成
			dp[coins[0] * j] = 1;
		}
		for (int i = 1; i<coins.size(); ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				//dp[i][j] = dp[i - 1][j];//不用这一种硬币
				if (j >= coins[i])
				{
					// dp[i][j] += dp[i][j - coins[i]];//加一枚这种硬币
					dp[j] += dp[j - coins[i]];
				}
			}
		}
		//return dp[m - 1][amount];
		return dp[amount];
	}
};



//一维数组超简洁版
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int m = coins.size();
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = coins[i - 1]; j <= amount; ++j)
			{
				dp[j] += dp[j - coins[i - 1]];
			}
		}
		return dp[amount];
	}
};


//复习
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		// if(coins.size()==0||amount<0)
		// {
		//     return 0;
		// }//如果amount是0，就算coins.size()==0，也应该返回1
		int m = coins.size();
		vector<vector<int>> dp(m + 1, vector<int>(amount + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 0; j <= amount; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= coins[i - 1])
				{
					dp[i][j] += dp[i][j - coins[i - 1]];
				}
			}
		}
		return dp[m][amount];
	}
};