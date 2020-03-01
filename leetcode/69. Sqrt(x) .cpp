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