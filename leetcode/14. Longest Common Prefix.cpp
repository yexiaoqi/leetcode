//Write a function to find the longest common prefix string amongst an array of strings.

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string compre;
		if (!strs.size())//不是 if(!strs)
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


//复习，自己的方法
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		if (strs.size() == 0)
		{
			return res;
		}
		int minsize = strs[0].size();
		for (int i = 1; i<strs.size(); ++i)
		{
			if (minsize>strs[i].size())
			{
				minsize = strs[i].size();
			}
		}
		for (int i = 0; i<minsize; ++i)
		{
			int j = 1;
			for (j; j<strs.size(); ++j)
			{
				if (strs[j][i] != strs[0][i])
				{
					return res;
				}
			}
			if (j == strs.size())
			{
				res += strs[0][i];
			}
		}
		return res;
	}
};

//简化
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		if (strs.size() == 0)
		{
			return res;
		}
		// int minsize=strs[0].size();
		// for(int i=1;i<strs.size();++i)
		// {
		//     if(minsize>strs[i].size())
		//     {
		//         minsize=strs[i].size();
		//     }
		// }
		//for(int i=0;i<minsize;++i)
		for (int i = 0; i<strs[0].size(); ++i)
		{
			int j = 1;
			for (j; j<strs.size(); ++j)
			{
				if (i >= strs[j].size() || strs[j][i] != strs[0][i])
					//if(strs[j][i]!=strs[0][i])
				{
					return res;
				}
			}
			res += strs[0][i];
			//不需要下面的if
			// if(j==strs.size())
			// {
			//     res+=strs[0][i];
			// }
		}
		return res;
	}
};