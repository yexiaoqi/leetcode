//自己做出
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, 0);
		int num = 1;
		while (num*num <= n)
		{
			dp[num*num] = 1;
			++num;
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j<num; ++j)
			{
				if (i>j*j&&dp[i - j*j])
				{
					if (dp[i] == 0 || dp[i]>dp[i - j*j] + 1)
					{
						dp[i] = dp[i - j*j] + 1;
					}
				}
			}
		}
		return dp.back();
	}
};

//方法二，四平方和定理
class Solution {
public:
	int numSquares(int n) {
		while (n % 4 == 0)
		{
			n /= 4;//注意用while，要先用除以4化简才能用n%8==7判断
		}
		if (n % 8 == 7)
		{
			return 4;
		}
		for (int i = 0; i*i<n; ++i)
		{
			int j = sqrt(n - i*i);
			if (i*i + j*j == n)
			{
				return !!i + !!j;
			}
		}
		return 3;
	}
};

//方法三
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 1; i + j*j <= n; ++j)
			{
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
		}
		return dp.back();//这种方法更新顺序是1,4,9,2,5,10,3,6,11,4,7,12,5,8,6,9,7,10,8,11,9,12,10,11,12
	}
};

//方法四（推荐）
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j*j <= i; ++j)
			{
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp.back();//这种方法更新顺序是0,1,2,3,4,5
	}
};