//ͬ��ָoffer16
bool g_Invalid = false;//��Ч����ʱΪtrue
class Solution {
public:
	bool equal(double a, double b)
	{
		if (abs(a - b)<0.0000001)
		{
			return true;
		}
		return false;
	}//double������==�Ƿ����
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
		ln = abs(ln);
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
		if (n & 0x1 == 1)//���n������
		{
			res *= x;
		}
		return res;
	}
};