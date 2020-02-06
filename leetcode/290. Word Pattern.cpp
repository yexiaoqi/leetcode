class Solution {
public:
	bool wordPattern(string pattern, string str) {
		string word;
		char used[128] = {};
		map<string, char> word_map;
		str.push_back(' ');
		int pos = 0;
		for (int i = 0; i<str.length(); ++i)
		{
			if (str[i] == ' ')
			{
				if (pos == pattern.length())
				{
					return false;
				}
				if (word_map.find(word) == word_map.end())
				{
					if (used[pattern[pos]])
					{
						return false;
					}
					word_map[word] = pattern[pos];
					used[pattern[pos]] = 1;
				}
				else
				{
					if (word_map[word] != pattern[pos])
					{
						return false;
					}
				}
				word = "";
				++pos;
			}
			else
			{
				word += str[i];
			}
		}
		if (pos != pattern.length())
		{
			return false;
		}
		return true;
	}
};


