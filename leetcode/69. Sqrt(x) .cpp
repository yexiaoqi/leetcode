//方法一
//算一个候选值的平方，然后和x比较大小，为了缩短查找时间，我们采用二分搜索法来找平方根
//加测试用例
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
		long left = 0, right = x;//要用long型，否则(mid+1)*(mid+1)会溢出
		while (left <= right)
		{
			long mid = (left + right) / 2;//要用long型，否则(mid+1)*(mid+1)会溢出
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
		return -1;//return -1是必要的
	}
};


//复习
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