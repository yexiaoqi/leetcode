class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		// int res=0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int gsize = g.size();//kid
		int ssize = s.size();//cookie
		int child = 0;//kid
		int cookie = 0;//cookie
		while (child<gsize&&cookie<ssize)
			//for(int i=0;i<s.size();++i)
		{
			if (s[cookie] >= g[child])
			{
				//res+=1;
				++child;
			}
			++cookie;

		}
		return child;
	}
};