//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.


//本题由于限制了输入数字范围这一特殊性，故而还有一种利用贪婪算法的解法，建立一个数表，
//每次通过查表找出当前最大的数，减去再继续查表，
class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		vector<int> val{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> str{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		for (int i = 0; i < val.size(); ++i) {
			while (num >= val[i]) {
				num -= val[i];
				res += str[i];
			}
		}
		return res;
	}
};


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