//Given a non - negative integer represented as a non - empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.

class Solution
{
	//【题意】 给你一个用数组表示的数，求加一之后的结果，结果还是用数组表示。
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n - 1;i >= 0;i--)//注意是n-1不是n
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;//只要加1，所以加了1以后要立刻结束return
			}
		}
		digits[0] = 1;
		digits.push_back(0);//针对例如99这样的数，在上面的for循环后变为00，现在把第一个0变为1，在在末尾添上一个0，变为100
		return digits;
	}
};


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				++digits[i];
				return digits;
			}
		}
		if (digits[0] == 0)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};