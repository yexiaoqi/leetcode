//ͬleetcode242
class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> m;
		for (int i = 0; i<s.size(); ++i)
		{
			++m[s[i]];
		}
		for (int i = 0; i<t.size(); ++i)
		{
			if (m.count(t[i]) && m[t[i]] != 0)
			{
				--m[t[i]];
			}
			else
			{
				return false;
			}
		}
		for (auto a = m.begin(); a != m.end(); ++a)
		{
			if ((*a).second != 0)
			{
				return false;
			}
		}
		return true;
	}
};