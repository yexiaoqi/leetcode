class Solution {
public:
	int longestPalindrome(string s) {
		int char_map[128] = { 0 };
		int flag = 0;
		int max_length = 0;
		for (int i = 0; i<s.length(); ++i)
		{
			++char_map[s[i]];
		}
		for (int i = 0; i<128; ++i)
		{
			if (char_map[i] % 2 != 0)
			{
				flag = 1;
				max_length += char_map[i] - 1;
			}
			else
			{
				max_length += char_map[i];
			}
		}
		return max_length + flag;
	}
};

//¸´Ï°
class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> m;
		for (int i = 0; i<s.size(); ++i)
		{
			++m[s[i]];
		}
		bool flag = false;
		int cnt = 0;
		for (auto a = m.begin(); a != m.end(); ++a)
		{
			if ((*a).second & 0x1)
			{
				flag = true;
				cnt += (*a).second - 1;
			}
			else
			{
				cnt += (*a).second;
			}
		}
		if (flag)
		{
			cnt += 1;
		}
		return cnt;
	}
};