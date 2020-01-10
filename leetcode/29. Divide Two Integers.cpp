//自己的方法，用了加减超时
class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = ((dividend >= 0 && divisor>0) || (dividend <= 0 && divisor<0)) ? 1 : 0;
		int res = 0;
		if (divisor == INT_MIN)
		{
			return dividend == INT_MIN ? 1 : 0;
		}
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
			{
				return INT_MAX;
			}
			dividend = flag ? dividend - divisor : dividend + divisor;
			++res;
		}
		while (abs(dividend) >= abs(divisor))
		{
			dividend = flag ? dividend - divisor : dividend + divisor;
			++res;
		}
		if (!flag)
		{
			res = -res;
		}
		return res;
	}
};

//正确方法
class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = (dividend >= 0 ^ divisor>0) ? 0 : 1;//用异或替代下面这句
													   //int flag=((dividend>=0&&divisor>0)||(dividend<=0&&divisor<0))?1:0;
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
			{
				return INT_MAX;
			}
		}
		long m = labs(dividend), n = labs(divisor);//使用long型，abs变成labs
		long res = 0;//使用long型
		while (m >= n)
		{
			long t = n, p = 1;//使用long型
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