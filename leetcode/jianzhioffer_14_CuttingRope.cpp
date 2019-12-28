//����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊk[0], k[1], ..., k[m]������k[0]xk[1]x...xk[m]���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��


//��̬�滮��O(n*2)ʱ��
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

//O(1)�ⷨ
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