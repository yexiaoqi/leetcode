//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> T =
		{
			{ 'I',1 },
			{ 'V',5 },
			{ 'X',10 },
			{ 'L',50 },
			{ 'C',100 },
			{ 'D',500 },
			{ 'M',1000 },//ע�⣬��char��������''������""
		};
		int sum = T[s.back()];
		for (int i = s.size() - 2;i >= 0;--i)
		{
			if (T[s[i]]<T[s[i + 1]])
			{
				sum -= T[s[i]];
			}
			else
			{
				sum += T[s[i]];
			}
		}
		return sum;
	}
};

//��ϰ
class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> m{ { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },
		{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
		for (int i = 0; i<s.size(); ++i)
		{
			if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
			{
				res += m[s[i]];
			}
			else
			{
				res -= m[s[i]];
			}
		}
		return res;
	}
};


//��ϰ��һ��ac
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> m{ { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
		if (s.size() == 0)
		{
			return 0;
		}
		int res = m[s[0]];
		for (int i = 1; i<s.size(); ++i)
		{
			if (m[s[i]]>m[s[i - 1]])
			{
				res += m[s[i]] - 2 * m[s[i - 1]];
			}
			else
			{
				res += m[s[i]];
			}
		}
		return res;
	}
};