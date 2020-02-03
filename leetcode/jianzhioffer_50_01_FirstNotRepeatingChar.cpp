//同leetcdeo387
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> mapping;
        for(int i=0;i<str.size();++i)
        {
            /*if(mapping.find(str[i])==mapping.end())
            {
                mapping[str[i]]=1;
            }
            else
            {
                ++mapping[str[i]];
            }*/
             ++mapping[str[i]];
        }//直接建立即可
        for(int i=0;i<str.size();++i)
        {
            if(mapping[str[i]]==1)
            {
                return i;
            }
        }
        return -1;
       /*int res=-1;
        char s=str[0];
        int j=0;
        for(auto i=mapping.begin();i!=mapping.end();++i)
        {
            if(i->second==1)
            {
                if(s!=i->first)
                {
                    ++j;
                    s=str[j];
                }
                else
                {
                    res=j;
                    return res;
                }
            }
        }
        return res;*///这样写不行，因为map会自动排序，所以mapping中的顺序不是字符串中的顺序
    }
};


//复习，一遍ac，简单
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
		{
			return -1;
		}
		unordered_map<char, int> m;
		for (int i = 0; i<str.size(); ++i)
		{
			++m[str[i]];
		}
		for (int i = 0; i<str.size(); ++i)
		{
			if (m[str[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};