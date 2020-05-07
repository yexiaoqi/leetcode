//同指南5_1
//自己的方法，一遍ac
class Solution {
public:
	bool isAnagram(string s, string t) {
		int size1 = s.size();
		int size2 = t.size();
		if (size1 != size2)
		{
			return false;
		}
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for (int i = 0; i<size1; ++i)
		{
			if (s[i] != t[i])
			{
				return false;
			}
		}
		return true;
	}
};

//自己的方法二
class Solution {
public:
	bool isAnagram(string s, string t) {
		int size1 = s.size();
		int size2 = t.size();
		if (size1 != size2)
		{
			return false;
		}
		unordered_map<int, int> m;
		for (int i = 0; i<size1; ++i)
		{
			++m[s[i] - 'a'];
		}
		for (int i = 0; i<size2; ++i)
		{
			if (m.find(t[i] - 'a') == m.end())
			{
				return false;
			}
			--m[t[i] - 'a'];
		}
		for (int i = 0; i<26; ++i)
		{
			if (m[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
};