enum Status { kValid = 0, kInvaid };//全局变量区分是不合法输入导致的0还是数字0
//注意空字符串、无效输入、正负号、溢出的处理
int g_status = kValid;
class Solution {
public:
	int StrToInt(string str) {
		int res = 0;
		if (str.size() == 0)
		{
			g_status = kInvaid;
			return 0;
		}
		int sign = 1;
		for (int i = 0; i<str.size(); ++i)
		{
			if (i == 0 && (str[i] == '+' || str[i] == '-'))
			{
				sign = (str[i] == '+') ? 1 : 0;
				continue;
			}
			if (str[i]<'0' || str[i]>'9')
			{
				g_status = kInvaid;
				return 0;
			}
			if (res>INT_MAX / 10 || (res == INT_MAX / 10 && (sign + str[i] - '0'>8)))
			{
				g_status = kInvaid;
				return 0;
			}
			res = res * 10 + str[i] - '0';
		}
		if (sign == 0)
		{
			res = -res;
		}
		return res;
	}
};