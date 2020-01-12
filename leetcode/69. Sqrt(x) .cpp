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
		return -1;
	}
};