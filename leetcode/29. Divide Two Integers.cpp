//�Լ��ķ��������˼Ӽ���ʱ
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

//��ȷ���������к����ƽ��ǵ���ĸо������ʾ���һ���������ö�������ʾ������Ӧ���ö�����ȥ��ʾ
class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = (dividend >= 0 ^ divisor>0) ? 0 : 1;//���������������
													   //int flag=((dividend>=0&&divisor>0)||(dividend<=0&&divisor<0))?1:0;
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
			{
				return INT_MAX;
			}
		}
		long m = labs(dividend), n = labs(divisor);//ʹ��long�ͣ�abs���labs
		long res = 0;//ʹ��long��
		while (m >= n)
		{
			long t = n, p = 1;//ʹ��long��
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


//��ϰ
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN&&divisor == -1)
		{
			return INT_MAX;
		}
		long m = labs(dividend), n = labs(divisor);
		int flag = (dividend>0) ^ (divisor>0) ? -1 : 1;
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

		return flag == 1 ? res : -res;
	}
};