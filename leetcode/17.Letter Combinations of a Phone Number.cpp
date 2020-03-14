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
			str.pop_back();//×¢ÒâÃ»ÓÐ-= !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
};


//¸´Ï°
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
		{
			return vector<string>();
		}
		unordered_map<char, string> m{ { '2',"abc" },{ '3',"def" },{ '4',"ghi" },{ '5',"jkl" },
		{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz" } };
		vector<string> res;
		string str = "";
		Combinations(digits, str, res, 0, m);
		return res;
	}
	void Combinations(string digits, string &path, vector<string> &res, int pos, unordered_map<char, string> &m)
	{
		if (path.size() == digits.size())
		{
			res.push_back(path);
			return;
		}
		for (int j = 0; j<m[digits[pos]].size(); ++j)
		{
			path.push_back(m[digits[pos]][j]);
			++pos;
			Combinations(digits, path, res, pos, m);
			path.pop_back();
			--pos;
		}
	}
};

//¸´Ï°
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
		{
			return vector<string>();
		}
		unordered_map<char, string> m{ { '2',"abc" },{ '3',"def" },{ '4',"ghi" },{ '5',"jkl" },
		{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },{ '9',"wxyz" } };
		vector<string> res;
		string word = "";
		Combinations(digits, m, word, 0, res);
		return res;
	}
	void Combinations(string digits, unordered_map<char, string> &m, string &word, int pos, vector<string> &res)
	{
		if (pos == digits.size())
		{
			res.push_back(word);
			return;
		}
		for (int i = 0; i<m[digits[pos]].size(); ++i)
		{
			word.push_back(m[digits[pos]][i]);
			++pos;
			Combinations(digits, m, word, pos, res);
			--pos;
			word.pop_back();
		}
	}
};