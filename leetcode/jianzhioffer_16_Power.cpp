//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//
//保证base和exponent不同时为0

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
		while (ex / 2)
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