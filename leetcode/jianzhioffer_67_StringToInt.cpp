//ͬleetcode8
enum Status { kValid = 0, kInvaid };//ȫ�ֱ��������ǲ��Ϸ����뵼�µ�0��������0
//ע����ַ�������Ч���롢�����š�����Ĵ���
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
			res = str[i] - '0' + res * 10;//ע�ⲻҪ©����0,������ res * 10 + str[i] - '0'���������ȼ��� res * 10 + str[i]���Ѿ�������ټ�0û��
		}
		if (sign == 0)
		{
			res = -res;
		}
		return res;
	}
};



//��ϰ���Լ�����
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
				if (res>INT_MAX / 10 || ((res == INT_MAX / 10) && (str[i] - '0'>7 - flag)))//ע���ж�str[i]-'0'������str[i]
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