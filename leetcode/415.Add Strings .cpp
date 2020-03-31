class Solution {
public:
	string addStrings(string num1, string num2) {
		string res = "";
		int m = num1.size(), n = num2.size();
		int carry = 0;
		int i = m - 1, j = n - 1;
		while (i >= 0 || j >= 0)
		{
			int val1 = i >= 0 ? num1[i] - '0' : 0;
			int val2 = j >= 0 ? num2[j] - '0' : 0;
			int sum = val1 + val2 + carry;
			//res.insert(res.begin(),to_string(sum%10));//insert用迭代器时，后面只能是char
			res.insert(res.begin(), sum % 10 + '0');
			cout << val2 << endl;
			carry = sum / 10;
			--i;
			--j;
		}
		if (carry)
		{
			res.insert(res.begin(), '1');
		}
		return res;
	}
};