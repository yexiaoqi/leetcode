//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

class Solution
{
public:
	string intToRoman(int num)
	{
		string s[4][10] =
		{
			{ "","I","II","III","IV","V","VI","VII","VIII","IX" },
			{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
			{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
			{ "","M","MM","MMM" },//,不是;
		};//不要漏了;
		return s[3][num / 1000 % 10] + s[2][num / 100 % 10] + s[1][num / 10 % 10] + s[0][num % 10];
	}
};