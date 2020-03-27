
class Solution
{
public:
	int lengthoflongest(string s)
	{
		unordered_map<char, int> m;
		vector<int> startindexes;
		//vector<pair<int,int>> postart;
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
				//postart.push_back(make_pair(res,left+1));
				startindexes.clear();
				startindexes.push_back(left + 1);
			}
			else if (res == i - left)
			{
				startindexes.push_back(left + 1);
			}
		}
		/*	for (int i = 0; i<s.size() - res + 1; ++i)
		{
		unordered_set<char> tmp;
		int j = 0;
		for (; j<res; ++j)
		{
		if (tmp.count(s[i + j]))
		{
		break;
		}
		tmp.insert(s[i + j]);
		}
		if (j == res)
		{
		startindexes.push_back(i);
		}
		}*/
		// for(auto a=postart.begin();a!=postart.end();++a)
		// {
		//   	if((*a).first==res)
		//     {
		//       	startindexes.push_back((*a).second);
		//     }
		// }
		for (int i = 0; i<startindexes.size(); ++i)
		{
			cout << startindexes[i] << endl;
		}
		return res;
	}
};

