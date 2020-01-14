class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (s.empty())
		{
			return vector<vector<string>>();
		}
		vector<vector<string>> res;
		vector<string> path;
		find(s, 0, res, path);
		return res;
	}
	void find(string s, int start, vector<vector<string>> &res, vector<string> &path)
	{
		if (start == s.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = start; i<s.size(); ++i)
		{
			if (!ispalindrome(s, start, i))
			{
				continue;
			}
			path.push_back(s.substr(start, i - start + 1));
			find(s, i + 1, res, path);
			path.pop_back();
		}
	}
	bool ispalindrome(string s, int start, int end)
	{
		while (start<end)
		{
			if (s[start++] != s[end--])
			{
				return false;
			}
		}
		return true;
	}
};