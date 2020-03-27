class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.size() == 0)
		{
			return vector<int>();
		}
		unordered_map<string, int> wordm;
		int m = s.size(), n = words.size(), len = words[0].size();
		for (int i = 0; i<n; ++i)
		{
			++wordm[words[i]];
		}
		vector<int> res;
		for (int i = 0; i<m - n*len + 1; ++i)
		{
			unordered_map<string, int> cmpm;
			int j = 0;
			for (; j<n; ++j)
			{
				string tmp = s.substr(i + j*len, len);
				if (!wordm.count(tmp))
				{
					break;
				}
				++cmpm[tmp];
				if (cmpm[tmp]>wordm[tmp])
				{
					break;
				}
			}
			if (j == n)
			{
				res.push_back(i);
			}
		}
		return res;
	}
};