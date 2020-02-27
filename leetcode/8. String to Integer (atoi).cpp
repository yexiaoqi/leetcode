//相似剑指offer67
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

//字符串转整数，有以下四个注意点：1.前面空格的处理2.溢出处理3.无效字符的忽略4.正负号的处理
//该题中，数字之后如果出现其他符号，直接抛弃后面部分返回即可
class Solution
{
public:
	int myAtoi(string str)
	{
		int sign = 1, i = 0;
		long base = 0;//base不能是int
		while (str[i] == ' ')
		{
			++i;
		}
		//若第一个非空格字符是符号+/-，则标记sign的真假，这道题还有个局限性，那就是在c++里面，+-1和-+1都是认可的，都是-1，而在此题里，则会返回0
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
			base = base * 10 + str[i++] - '0';//别忘记-'0'
		}
		return base*sign;//注意*sign
	}
};


//复习
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