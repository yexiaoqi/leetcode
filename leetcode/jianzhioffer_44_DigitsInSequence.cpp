//简洁版
class Solution {
public:
	int findNthDigit(int index) {
		if (index < 0)
		{
			return -1;
		}
		int digits = 1;
		while (true)
		{
			long num = digits == 1 ? 10 : 9 * pow(10, digits - 1);
			long tmp = num*digits;//注意要先long(num)，否则还是不对
			if (index<tmp)
			{
				return Finddigit(index, digits);
			}
			index -= digits*num;
			++digits;
		}
		return -1;
	}
	int Finddigit(int index, int digits)
	{
		int beginnum = digits == 1 ? 0 : pow(10, digits - 1);
		int num = beginnum + index / digits;
		int indexfromright = digits - index%digits;
		for (int i = 1; i<indexfromright; ++i)
		{
			num /= 10;
		}
		return num % 10;
	}
};


class Solution {
public:
	int findNthDigit(int index) {
		if (index < 0)
		{
			return -1;
		}
		int digits = 1;
		while (true)
		{
			int num = countofnum(digits);
			long tmp = long(num)*digits;//注意要先long(num)，否则还是不对
			if (index<tmp)
			{
				return Finddigit(index, digits);
			}
			index -= digits*num;
			++digits;
		}
		return -1;
	}
	int countofnum(int digits)
	{
		if (digits == 1)
		{
			return 10;
		}
		int cnt = pow(10, digits - 1);
		return 9 * cnt;
	}
	int beginnum(int digits)
	{
		if (digits == 1)
		{
			return 0;
		}
		return pow(10, digits - 1);
	}
	int Finddigit(int index, int digits)
	{
		int num = beginnum(digits) + index / digits;
		int indexfromright = digits - index%digits;
		for (int i = 1; i<indexfromright; ++i)
		{
			num /= 10;
		}
		return num % 10;
	}
};

//下面这种对个位数有错
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