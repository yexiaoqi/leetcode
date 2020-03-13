//基本和剑指offer58一致
class Solution {
public:
	void reverse2(string &s, int begin, int end)
	{
		while (begin<end)
		{
			swap(s[begin++], s[end--]);
		}
	}
	string reverseWords(string s) {
		if (s.empty())
		{
			return "";
		}
		reverse(s.begin(), s.end());
		int i = 0;
		string res = "";
		while (i<s.size())
		{
			while (i<s.size() && s[i] == ' ')
			{
				++i;
			}
			if (i == s.size())
			{
				break;
			}
			int b = i;
			while (i<s.size() && s[i] != ' ')
			{
				++i;
			}
			reverse2(s, b, i - 1);
			res += s.substr(b, i - b);
			res += ' ';
		}
		res = res.substr(0, res.size() - 1);
		return res;
	}
};