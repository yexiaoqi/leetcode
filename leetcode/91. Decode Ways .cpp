//ͬ��ָoffer 46
class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0 || s[0] == 0)
		{
			return -1;
		}
		vector<int> dp(s.size() + 1, 0);//Ҫ����Ϊs.size()+1������dp[2]Ӧ�������ַ�����ʱ�����ȥif(i>=2)
		dp[0] = 1;
		for (int i = 1; i <= s.size(); ++i)
		{
			if (s[i - 1] != '0')
			{
				dp[i] += dp[i - 1];
			}
			if (i >= 2)
			{
				if (s[i - 2] == '1' || (s[i - 2] == '2'&&s[i - 1]<'7'))
				{
					dp[i] += dp[i - 2];
				}
			}
		}
		return dp.back();
	}
};