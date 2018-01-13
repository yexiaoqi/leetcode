//Write a function to find the longest common prefix string amongst an array of strings.

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string compre;
		if (!strs.size())//²»ÊÇ if(!strs)
		{
			return compre;
		}
		for (int i = 0;i<strs[0].size();++i)
		{
			char cur = strs[0][i];
			for (int j = 1;j<strs.size();++j)
			{
				if (i>strs[j].size() || cur != strs[j][i])
				{
					return compre;
				}
			}
			compre.push_back(cur);
		}
		return compre;
	}
};