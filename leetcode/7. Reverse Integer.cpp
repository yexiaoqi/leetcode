class Solution {
public:
	int reverse(int x) {
		int res = 0;//注意res必须初始化为0，否则leetcode通不过
		while (x != 0)
		{
			if (abs(res)>INT_MAX / 10)
			{
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};