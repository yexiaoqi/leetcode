//由于窗口在不停向右滑动，所以只关心每个字符最后出现的位置，并建立映射。窗口的右边界就是当前遍历到的字符的位置，
//为了求出窗口的大小，需要一个变量 left 来指向滑动窗口的左边界，这样，如果当前遍历到的字符从未出现过，
//那么直接扩大右边界，如果之前出现过，那么就分两种情况，在或不在滑动窗口内，如果不在滑动窗口内，那么就没事，
//当前字符可以加进来，如果在的话，就需要先在滑动窗口内去掉这个已经出现过的字符了，
//去掉的方法并不需要将左边界 left 一位一位向右遍历查找，由于 HashMap 已经保存了该重复字符最后出现的位置，
//所以直接移动 left 指针就可以了。维护一个结果 res，每次用出现过的窗口大小来更新结果 res，就可以得到最终结果啦。
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


//复习
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int maxlen = 0, index = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m[s[i]] == 0)
			{
				++m[s[i]];
				if (maxlen<i - index + 1)
				{
					maxlen = i - index + 1;
				}
			}
			else
			{
				int k = index;
				for (; k<i; ++k)
				{
					if (m[s[i]] != 0)
					{
						--m[s[k]];
					}
					else
					{
						break;
					}
				}
				index = k;
				++m[s[i]];
			}
		}
		return maxlen;
	}
};


//复习
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int left = -1, res = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m.count(s[i]) && m[s[i]]>left)
			{
				left = m[s[i]];
			}
			m[s[i]] = i;
			if (res<i - left)
			{
				res = i - left;
			}
		}
		return res;
	}
};