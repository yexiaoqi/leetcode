class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
		{
			return vector<string>();
		}
		map<char, string> m{ { '2',"abc" },{ '3',"def" },{ '4',"ghi" },
		{ '5',"jkl" },{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz" } };
		vector<string> res;
		string str = "";
		combination(digits, str, res, m, 0);
		return res;
	}
	void combination(string &digits, string &str, vector<string> &res, map<char, string> &m, int level)
	{
		if (str.size() == digits.size())
		{
			res.push_back(str);
			return;
		}
		for (int i = 0; i<m[digits[level]].size(); ++i)
		{
			str += m[digits[level]][i];
			combination(digits, str, res, m, level + 1);
			str.pop_back();//×¢ÒâÃ»ÓÐ-=
		}
	}
};