//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int i = a.size() - 1, j = b.size() - 1;
		string sum;
		int carry = 0;
		while (i >= 0 || j >= 0 || carry>0)
		{
			if (i >= 0)
			{
				carry += a[i--] - '0';
			}
			if (j >= 0)
			{
				carry += b[j--] - '0';
			}
			sum += carry % 2 + '0';
			carry /= 2;
		}
		reverse(sum.begin(), sum.end());
		return sum;
	}
};