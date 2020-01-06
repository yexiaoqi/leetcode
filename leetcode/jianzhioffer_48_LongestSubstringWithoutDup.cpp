//同leetcode3
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int left = -1;
		int res = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m.count(s[i]) && m[s[i]]>left)
			{
				left = m[s[i]];
			}
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};



//自己写的
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxlen = 0;
		unordered_map<char, int> mapping;//注意用unordered_map而不是map，unordered_map查找快
		int len = 0;
		int index = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (mapping[s[i]] == 0)//判断value而不是key
								   //以下这两个if都不对，因为map查找的是key，比如“tmmzuxt”，虽然在第二个m开始后，mapping[t]已经是0（value是0），但是还是有t（key不为0），所以最后一个t算不上去
								   //if (mapping.count(s[i]) == 0)
								   //if (mapping.find(s[i]) == mapping.end())
			{
				++len;
				mapping[s[i]] = 1;
				if (maxlen<len)
				{
					maxlen = len;
				}
			}
			else
			{
				while (s[index] != s[i])
				{
					--mapping[s[index]];
					++index;
				}
				len = i - index;
				++index;
			}
		}
		return maxlen;
	}
};



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;
		int result = 0;
		string word = "";
		int char_map[128] = { 0 };//注意初始化为0
		for (int i = 0; i<s.length(); ++i)
		{
			++char_map[s[i]];
			if (char_map[s[i]] == 1)
			{
				word += s[i];
				if (result<word.length())
				{
					result = word.length();
				}
			}
			else
			{
				while (char_map[s[i]]>1)
				{
					--char_map[s[begin]];
					++begin;
				}

				word = "";
				for (int j = begin; j <= i; ++j)
				{
					word += s[j];
				}
			}
		}
		return result;
	}
};