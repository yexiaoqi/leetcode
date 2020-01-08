//同剑指offer67
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
class Solution
{
public:
	int myAtoi(string str)
	{
		int sign = 1, i = 0, base = 0;
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