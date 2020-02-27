//���ƽ�ָoffer67
//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//	Notes : It is intended for this problem to be specified vaguely(ie, no given input specs).You are responsible to gather all the input requirements up front.
//
//	Update(2015 - 02 - 10) :
//	The signature of the C++ function had been updated.If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//	spoilers alert... click to show requirements for atoi.

//�ַ���ת�������������ĸ�ע��㣺1.ǰ��ո�Ĵ���2.�������3.��Ч�ַ��ĺ���4.�����ŵĴ���
//�����У�����֮����������������ţ�ֱ���������沿�ַ��ؼ���
class Solution
{
public:
	int myAtoi(string str)
	{
		int sign = 1, i = 0;
		long base = 0;//base������int
		while (str[i] == ' ')
		{
			++i;
		}
		//����һ���ǿո��ַ��Ƿ���+/-������sign����٣�����⻹�и������ԣ��Ǿ�����c++���棬+-1��-+1�����Ͽɵģ�����-1�����ڴ������᷵��0
		if (str[i] == '+' || str[i] == '-')
		{
			sign = 1 - 2 * (str[i++] == '-');
		}
		while (str[i] >= '0'&&str[i] <= '9')
		{
			if (base>INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0'>INT_MAX % 10))
			{
				if (sign == 1)
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
			}
			base = base * 10 + str[i++] - '0';//������-'0'
		}
		return base*sign;//ע��*sign
	}
};


//��ϰ
enum Status { Valid = 0, Invalid };
int g_status = Valid;
class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0)
		{
			g_status = Invalid;
			return 0;
		}
		int i = 0;
		long res = 0;
		while (str[i] == ' ')
		{
			++i;
		}
		int flag = 1;
		if (str[i] == '+' || str[i] == '-')
		{
			flag = str[i] == '+' ? 1 : 0;
			++i;
		}
		if (str[i]<'0' || str[i]>'9')
		{
			g_status = Invalid;
			return 0;
		}
		for (; i<str.size(); ++i)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				return flag ? res : -res;
			}
			if (res>INT_MAX / 10 || ((res == INT_MAX / 10) && (str[i] + flag - '0'>8)))
			{
				return flag == 1 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + (str[i] - '0');
		}
		if (!flag)
		{
			res = -res;
		}
		return res;
	}
};