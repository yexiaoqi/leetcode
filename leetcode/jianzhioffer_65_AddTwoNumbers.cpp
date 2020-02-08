//ͬleetcode 371
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		sum = num1;
		while (num2 != 0)
		{
			sum = num1^num2;
			carry = (num1&num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return sum;
	}
};

//复习
class Solution {
public:
	int Add(int num1, int num2)
	{
		int res = num1;
		while (num2)
		{
			res = num1^num2;//不能直接num1^=num2,后面还要用到原来的num1
			num2 = (num1&num2 & 0x7fffffff) << 1;
			num1 = res;
		}
		return res;
	}
};