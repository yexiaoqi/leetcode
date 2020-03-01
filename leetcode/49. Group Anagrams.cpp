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

//��ϰ
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;//string��key��value����λ�ʣ������Ϳ���������
		if (strs.size() == 0)
		{
			return vector<vector<string>>();
		}
		vector<vector<string>> res;
		for (int i = 0; i<strs.size(); ++i)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			//string s=sort(strs[i].begin(),strs[i].end());//sortû�з���ֵ��������������
			m[s].push_back(strs[i]);
		}
		for (auto i = m.begin(); i != m.end(); ++i)
		{
			res.push_back((*i).second);
		}
		return res;
	}
};



//��ϰ
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		vector<vector<string>> res;
		for (int i = 0; i<strs.size(); ++i)
		{
			string word = strs[i];
			sort(word.begin(), word.end());//sortû�з���ֵ��������������ôд
										   //string word=sort(strs[i].begin(),strs[i].end());
			m[word].push_back(strs[i]);
		}
		for (auto a = m.begin(); a != m.end(); ++a)
		{
			res.push_back((*a).second);//ע��(*a)
		}
		return res;
	}
};