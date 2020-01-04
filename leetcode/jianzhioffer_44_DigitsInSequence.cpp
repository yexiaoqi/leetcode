class Solution {
public:
	int findnum(int index)
	{
		if (index < 0)
		{
			return -1;
		}
		int digit = 1;
		int res = -1;
		int cntnum = 0;
		while (true)
		{
			if (digit == 1)
			{
				cntnum = 10;//由于从0开始，个位数有10个
			}
			else
			{
				cntnum = 9 * pow(10, digit - 1)*digit;
			}
			if (index > cntnum)
			{
				index -= cntnum;
				++digit;
			}
			else
			{
				int num = pow(10, digit - 1) + index / digit;
				int dex = digit - index%digit;
				for (int i = 1; i < dex; ++i)
				{
					num /= 10;
				}
				res = num % 10;
				return res;
			}
		}
	}
};