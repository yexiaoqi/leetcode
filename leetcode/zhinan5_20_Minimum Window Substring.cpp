class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> m;
		for (int i = 0; i<t.size(); ++i)
		{
			++m[t[i]];
		}
		int cnt = 0, left = 0;
		int minlen = INT_MAX;
		string res = "";
		for (int i = 0; i<s.size(); ++i)
		{
			--m[s[i]];
			if (m[s[i]] >= 0)
			{
				++cnt;
			}
			while (cnt == t.size())
			{
				if (minlen>i - left + 1)
				{
					minlen = i - left + 1;
					res = s.substr(left, minlen);
				}
				++m[s[left]];
				if (m[s[left]]>0)
				{
					--cnt;
				}
				++left;
			}
		}
		return res;
	}
};