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