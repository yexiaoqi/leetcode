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