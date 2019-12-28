//给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0], k[1], ..., k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。


//动态规划，O(n*2)时间
class Solution {
public:
	int cutRope(int number) {
		if (number <= 1)
		{
			return 0;
		}
		if (number == 2)
		{
			return 1;
		}
		if (number == 3)
		{
			return 2;
		}
		vector<int> dp(number + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= number; ++i)
		{
			for (int j = 1; j <= i / 2; ++j)
			{
				if (dp[j] * dp[i - j]>dp[i])
				{
					dp[i] = dp[j] * dp[i - j];
				}
			}
		}
		return dp[number];
	}
};

//O(1)解法
class Solution {
public:
	int cutRope(int number) {
		if (number <= 1)
		{
			return 0;
		}
		if (number == 2)
		{
			return 1;
		}
		if (number == 3)
		{
			return 2;
		}
		int cnt3 = number / 3;
		if (number % 3 == 1)
		{
			--cnt3;
		}
		int cnt2 = number - cnt3 * 3;
		return pow(3, cnt3)*cnt2;
	}
};