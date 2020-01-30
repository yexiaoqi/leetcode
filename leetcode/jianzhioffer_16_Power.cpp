//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//
//保证base和exponent不同时为0
//同leetcode50
class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0)
		{
			return 0;
		}
		double res = 1;
		int ex = abs(exponent);
		for (int i = 0; i<ex; ++i)
		{
			res *= base;
		}
		if (exponent<0)
		{
			res = 1 / res;
		}
		return res;
	}
};


//进一步优化
//牛客上例子不全，下面是错的
class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0)
		{
			return 0;
		}
		double res = base;
		int ex = abs(exponent);
		if (!exponent)
		{
			return 1;
		}
		while (ex / 2)//比如2的10次方，就只能得到512
		{
			res *= res;
			ex = ex >> 1;
		}
		if (ex & 0x1)
		{
			res *= base;
		}
		if (exponent<0)
		{
			res = 1 / res;
		}
		return res;
	}
};

//正确做法
bool g_Invalid = false;
class Solution {
public:
	bool equal(double a, double b)
	{
		if (abs(a - b)<0.0000001)
		{
			return true;
		}
		return false;
	}
	double myPow(double x, int n)
	{
		if (equal(x, 0.0) && n<0)
		{
			g_Invalid = true;
			return 0.0;
		}
		if (n == 0)
		{
			return 1;
		}
		long ln = n;
		int flag = ln>0 ? 1 : 0;
		ln = abs(ln);//由于INT_MIN直接abs是不对的，所以要变成long型的ln
		double res = Pow(x, ln);
		if (!flag)
		{
			res = 1 / res;
		}
		return res;
	}
	double Pow(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		if (n == 1)
		{
			return x;
		}
		double res = Pow(x, n / 2);
		res *= res;
		if (n & 0x1 == 1)//如果n是奇数
		{
			res *= x;
		}
		return res;
	}
};

//复习
bool g_Invalid = false;
class Solution {
public:
	bool equal(double a, double b)
	{
		if (abs(a - b)<0.00000001)
		{
			return true;
		}
		return false;
	}
	double myPow(double base, int exponent) {
		if (equal(base, 0.0) && exponent<0)
		{
			g_Invalid = true;
			return 0.0;
		}
		if (exponent == 0)
		{
			return 1.0;
		}
		int sign = exponent>0 ? 1 : -1;
		long ex = long(exponent);
		ex = labs(ex);
		double res = 1;
		res = power(base, exponent, res);
		if (sign == -1)
		{
			res = 1.0 / res;
		}
		return res;
	}
	double power(double base, int exponent, double &res)
	{
		if (exponent == 0)
		{
			return 1;
		}
		if (exponent == 1)
		{
			return base;
		}
		res = power(base, exponent / 2, res);
		res *= res;
		if (exponent & 0x1)
		{
			res *= base;
		}
		return res;
	}
};