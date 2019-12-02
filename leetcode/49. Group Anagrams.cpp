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

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> res_map;
		for (int i = 0; i<int(strs.size()); ++i)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			res_map[str].push_back(strs[i]);
		}
		for (auto it = res_map.begin(); it != res_map.end(); ++it)
		{
			res.push_back((*it).second);
		}
		return res;
	}
};