class Solution {
public:
	int numTrees(int n) {
		long res = 1;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			res = res*i / (i - n);
		}
		res = res / (n + 1);
		return res;
	}
};

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);//ÊÇdp(n+1)²»ÊÇdp[n+1]
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				dp[i] += dp[j] * dp[i - 1 - j];
			}
		}
		return dp[n];
	}
};

//¸´Ï°
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				dp[i] += dp[j] * dp[i - 1 - j];
			}
		}
		return dp[n];
	}
};

class Solution {
public:
	int numTrees(int n) {
		long res = 1;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			res = res*i / (i - n);
		}
		res /= (n + 1);
		return res;
	}
};