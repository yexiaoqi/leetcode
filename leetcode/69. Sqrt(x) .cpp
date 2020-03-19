//����һ
//��һ����ѡֵ��ƽ����Ȼ���x�Ƚϴ�С��Ϊ�����̲���ʱ�䣬���ǲ��ö�������������ƽ����
//�Ӳ�������
class Solution
{
public:
	int mySqrt(int x)
	{
		long left = 0, right = x;
		while (left <= right)
		{
			long mid = (left + right) / 2;
			if (mid*mid <= x && (mid + 1)*(mid + 1)>x)
			{
				return mid;
			}
			else if (mid*mid>x)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return -1;
	}
	void testall()
	{
		test(INT_MAX);
		test(-1);
		test(8);
		test(4);
		test(0);
	}
	void test(int x)
	{
		cout << mySqrt(x) << endl;
	}
};




class Solution {
public:
	int mySqrt(int x)
	{
		long left = 0, right = x;//Ҫ��long�ͣ�����(mid+1)*(mid+1)�����
		while (left <= right)
		{
			long mid = (left + right) / 2;//Ҫ��long�ͣ�����(mid+1)*(mid+1)�����
			if (x >= mid*mid&&x<(mid + 1)*(mid + 1))
			{
				return mid;
			}
			else if (x >= (mid + 1)*(mid + 1))
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;//return -1�Ǳ�Ҫ��
	}
};


//��ϰ
class Solution {
public:
	int mySqrt(int x) {
		long left = 0, right = x;
		while (left <= right)
		{
			long mid = (left + right) / 2;
			if ((x >= mid*mid) && (x<(mid + 1)*(mid + 1)))
			{
				return mid;
			}
			else if (x<mid*mid)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return -1;
	}
};