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
					dp[i][j] = 1;//���ֻ��һ��Ӳ�ң���ôֻ���������������ܹ���
				}
				if (i >= 1)
				{
					dp[i][j] = dp[i - 1][j];//������һ��Ӳ��
					if (j >= coins[i])
					{
						dp[i][j] += dp[i][j - coins[i]];//��һö����Ӳ��
					}
				}
			}
		}
		return dp[m - 1][amount];
	}
};

//�Ż�Ϊһά����
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