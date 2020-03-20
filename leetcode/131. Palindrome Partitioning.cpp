//不够快
https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/
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

//优化
class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (s.empty())
		{
			return vector<vector<string>>();
		}
		vector<vector<string>> res;
		vector<string> path;
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
		for (int i = 0; i<s.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if ((s[i] == s[j]) && (i - j <= 2 || dp[j + 1][i - 1]))//从j+1到i-1字符串
				{
					dp[j][i] = true;
				}
			}
		}
		find(s, 0, res, path, dp);
		return res;
	}
	void find(string s, int start, vector<vector<string>> &res, vector<string> &path,
		vector<vector<bool>> &dp)
	{
		if (start == s.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = start; i<s.size(); ++i)
		{
			if (!dp[start][i])
			{
				continue;
			}
			path.push_back(s.substr(start, i - start + 1));
			find(s, i + 1, res, path, dp);
			path.pop_back();
		}
	}
};