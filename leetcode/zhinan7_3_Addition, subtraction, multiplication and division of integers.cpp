//用位运算实现加减乘除


//实现加同leetcode371
int add(int a, int b) {
	int res = a;
	while (b)
	{
		int tmp = (a&b & 0x7fffffff) << 1;//要加(),<<的运算级别高
		a = a^b;
		b = tmp;
	}
	return a;
}


//实现减
int negnum(int n)
{
	return add(~n, 1);
}
int minus1(int a, int b)
{
	return add(a, negnum(b));
}

//实现乘
int multi(int a, int b)
{
	int res = 0;
	while (b)
	{
		if (b & 1)
		{
			res = add(res, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return res;
}

//实现除法，leetcode29
class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = (dividend >= 0) ^ (divisor >= 0) ? 0 : 1;
		if (dividend == INT_MIN&&divisor == -1)
		{
			return INT_MAX;
		}
		long m = labs(dividend), n = labs(divisor);
		long res = 0;
		while (m >= n)
		{
			long t = n, p = 1;
			while (m >= (t << 1))
			{
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		if (!flag)
		{
			res = -res;
		}
		return res;
	}
};