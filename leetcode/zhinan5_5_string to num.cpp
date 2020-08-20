class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
		{
			return 0;
		}
		int flag = 0;
		long res = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			flag = str[0] == '+' ? 0 : 1;
		}
		else if (str[0]>'9' || str[0]<'0')
		{
			return 0;
		}
		else
		{
			res = str[0] - '0';
		}
		for (int i = 1; i<str.size(); ++i)
		{
			if (str[i]>'9' || str[i]<'0')
			{
				return 0;
			}
			else
			{
				res = res * 10 + (str[i] - '0');
				if (res>INT_MAX + flag)
				{
					return 0;
				}
			}
		}
		if (flag)
		{
			res = -res;
		}
		return res;
	}
};



int g_Invalid = false;
class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0)
		{
			g_Invalid = true;
			return 0;
		}
		int flag = 0;
		int res = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			flag = str[0] == '+' ? 0 : -1;
			if (str[1] == '\0')
			{
				g_Invalid = true;
				return 0;
			}
		}
		else if (str[0]>'9'&&str[0]<'0')
		{
			g_Invalid = true;
			return 0;
		}
		else
		{
			res = str[0] - '0';
		}
		for (int i = 1; i<str.size(); ++i)
		{
			if (str[i]>'9' || str[i]<'0')
			{
				g_Invalid = true;
				return 0;
			}
			else
			{
				if (res>INT_MAX / 10 || ((res == INT_MAX / 10) && (str[i] - '0'>7 - flag)))//注意判断str[i]-'0'而不是str[i]
				{
					g_Invalid = true;
					return 0;
				}
				res = res * 10 + (str[i] - '0');
			}
		}
		if (flag == 0)
		{
			return res;
		}
		return -res;
	}
};