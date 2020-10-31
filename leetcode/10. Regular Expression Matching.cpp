//ͬ��ָoffer 19
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}
		if (p.size() == 1)
		{
			return (s.size() == 1) && (s[0] == p[0] || p[0] == '.');
		}
		if (p[1] != '*')
		{
			if (s.empty())
			{
				return false;
			}
			return(s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		if (!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
			return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
		}
		return isMatch(s, p.substr(2));
	}
};


//��ϰ
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0 ? true : false;
		}
		if (p.size() == 1)
		{
			if ((s.size() == 1) && (p[0] == s[0] || (p[0] == '.')))//ע��s.size()==1��ÿ��&��Ҫ�ģ�����s="aa",p="a"
																   //if(p[0]==s[0]||((p[0]=='.')&&(s.size()==1)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (p[1] != '*')
		{
			if (p[0] == s[0] || ((p[0] == '.') && (s.size() >= 1)))
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (p[0] == s[0] || ((p[0] == '.') && (s.size() >= 1)))
			{
				return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};


//��ϰ2
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0;
		}
		if (p.size() == 1)
		{
			return (s.size() == 1 && (p[0] == s[0] || p[0] == '.'));
		}
		if (p[1] != '*')
		{
			if (s.empty())
			{
				return false;
			}
			return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		else
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};

//��ϰ3
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}
		else if (p.size() == 1)
		{
			return s.size() == 1 && (p[0] == s[0] || p[0] == '.');
		}
		else if (p[1] != '*')
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
				//p.substr(2)��ȥƥ��0����p��ȥƥ����
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};


//��ϰ
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0;
		}
		if (p.size() == 1)
		{
			if (s.size() != 1 || !(p[0] == s[0] || p[0] == '.'))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		if (p[1] != '*')
		{
			if (s.size()<1 || !(p[0] == s[0] || p[0] == '.'))
			{
				return false;
			}
			else
			{
				return isMatch(s.substr(1), p.substr(1));
			}
		}
		else
		{
			if (s.size() >= 1 && (s[0] == p[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};


//����2
//ʱ�临�Ӷȣ�O(mn)O(mn)������ mm �� nn �ֱ����ַ��� ss �� pp �ĳ��ȡ�������Ҫ��������е�״̬������ÿ��״̬�ڽ���ת��ʱ��ʱ�临�Ӷ�Ϊ O(1)O(1)��
//
//�ռ临�Ӷȣ�O(mn)O(mn)����Ϊ�洢����״̬ʹ�õĿռ䡣
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (j>1 && p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 2] || (i>0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = i>0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};