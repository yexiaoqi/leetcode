//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return :
//
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//Note: All inputs will be in lower - case.

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, multiset<string>> res;
		for (string s : strs)
		{
			string t = s;
			sort(t.begin(), t.end());
			res[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : res)
		{
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
};