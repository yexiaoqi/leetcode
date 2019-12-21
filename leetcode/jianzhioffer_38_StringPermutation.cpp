//题目描述
//输入一个字符串, 按字典序打印出该字符串中字符的所有排列。例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。
//输入描述 :
//输入一个字符串, 长度不超过9(可能有字符重复), 字符只包括大小写字母。


//几乎和leetcode47一样
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.length() == 0)
		{
			return res;
		}
		set<string> res_set;
		string  path;
		vector<int> visited(str.length(), 0);
		sort(str.begin(), str.end());
		dfs(str, res_set, path, 0, visited);
		return vector<string>(res_set.begin(), res_set.end());
	}
	void dfs(string str, set<string> &res, string  &s, int level, vector<int> &visited)
	{
		if (level == str.length())
		{
			res.insert(s);
			return;
		}
		for (int i = 0; i<int(str.length()); ++i)
		{
			if (visited[i] == 1)
			{
				continue;
			}
			s = s + str[i];
			visited[i] = 1;
			dfs(str, res, s, level + 1, visited);
			s.pop_back();
			visited[i] = 0;
		}
	}
};