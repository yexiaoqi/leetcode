//ͬ��ָoffer 46��ָ��4_13
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

//��ϰ
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0')//ע��s[0]=='0'
		{
			return 0;
		}
		vector<int> dp(s.size(), 0);
		dp[0] = 1;
		if (dp.size()>1)
		{
			if (s[1] != '0')
			{
				dp[1] += 1;
			}
			if ((s[0] == '1') || (s[0] == '2'&&s[1] <= '6'))
			{
				dp[1] += 1;
			}
		}//dp[1]Ҫ���⴦��
		for (int i = 2; i<s.size(); ++i)
		{
			if (s[i] != '0')
			{
				dp[i] += dp[i - 1];
			}
			if ((s[i - 1] == '1') || (s[i - 1] == '2'&&s[i] <= '6'))
			{
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
	}
};