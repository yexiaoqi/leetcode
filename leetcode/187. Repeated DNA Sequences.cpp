class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		map<string, int> word_map;
		vector<string> res;
		for (int i = 0; i <= s.length(); i++)//不能写成s.length()-10，因为可能s.length()<10
		{
			string word = s.substr(i, 10);
			if (word_map.find(word) != word_map.end())
			{
				word_map[word] += 1;
			}
			else
			{
				word_map[word] = 1;
			}
		}
		for (map<string, int>::iterator i = word_map.begin(); i != word_map.end(); ++i)
		{
			if (i->second>1)
			{
				res.push_back(i->first);
			}
		}
		return res;
	}
};