class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		restore(s, 4, "", res);
		return res;
	}
	void restore(string s, int k, string path, vector<string> &res)
	{
		if (k == 0)
		{
			if (s.empty())
			{
				res.push_back(path);
			}
			return;
		}
		for (int i = 1; i <= 3; ++i)
		{
			if (s.size() >= i&&isValid(s.substr(0, i)))
			{
				if (k == 1)
				{
					restore(s.substr(i), k - 1, path + s.substr(0, i), res);
				}
				else
				{
					restore(s.substr(i), k - 1, path + s.substr(0, i) + ".", res);
				}
			}
		}
	}
	bool isValid(string s)
	{
		if (s.size()>3 || s.size() <= 0 || (s.size()>1 && s[0] == '0'))
		{
			return false;
		}
		int tmp = stoi(s);
		return (tmp <= 255) && (tmp >= 0);
	}
};