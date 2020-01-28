//自己的方法，超出时间限制
class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size()<k)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i<s.size() - k + 1; ++i)
		{
			unordered_map<char, int> m;
			//bool judge=true;
			for (int j = i; j<s.size(); ++j)
			{
				bool judge = true;//应该放在这边判断，否则上一次为false扳不回来
				++m[s[j]];
				unordered_map<char, int>::iterator a;
				if (j - i + 1 >= k)
				{
					for (a = m.begin(); a != m.end(); ++a)
					{
						if ((*a).second<k)
						{
							judge = false;
							break;//直接break，不用continue看下一个
						}
					}
					if (judge == false)
						//if(a!=m.end())//不能这样，因为如果是最后一个不合格，也是不合格但却没有continue
					{
						continue;
					}
					if (res<j - i + 1)
					{
						res = j - i + 1;
					}
				}
			}
		}
		return res;
	}
};

//用普通数组替代map，还是超时
class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size()<k)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i<s.size() - k + 1; ++i)
		{
			int m[26] = { 0 };
			//unordered_map<char,int> m;
			//bool judge=true;
			for (int j = i; j<s.size(); ++j)
			{
				bool judge = true;//应该放在这边判断，否则上一次为false扳不回来
				++m[s[j] - 'a'];
				// unordered_map<char,int>::iterator a;
				if (j - i + 1 >= k)
				{
					for (int a = 0; a<26; ++a)
					{
						if (m[a] != 0 && m[a]<k)
						{
							judge = false;
							break;
						}
					}
					// for(a=m.begin();a!=m.end();++a)
					// {
					//     if((*a).second<k)
					//     {
					//         judge=false;
					//         continue;
					//     }
					// }
					if (judge == false)
						//if(a!=m.end())//不能这样，因为如果是最后一个不合格，也是不合格但却没有continue
					{
						continue;
					}
					if (res<j - i + 1)
					{
						res = j - i + 1;
					}
				}
			}
		}
		return res;
	}
};


//o(n^2)方法
class Solution {
public:
	int longestSubstring(string s, int k) {
		int res = 0, i = 0, n = s.size();
		while (i + k <= n)
			{
				int m[26] = { 0 }, mask = 0, max_idx = i;
				for (int j = i; j < n; ++j) {
					int t = s[j] - 'a';
					++m[t];
					if (m[t] < k)
						mask |= (1 << t);//如果其小于k，将 mask 的对应位改为1
					else
						mask &= (~(1 << t));//如果大于等于k，将 mask 对应位改为0
					if (mask == 0)
					{
						res = max(res, j - i + 1);
						max_idx = j;//比如baaacbbbb，k=2；第一次max_idx到a的位置，然后i从c再开始，之后还能发现更长的bbbb
					}
				}
				i = max_idx + 1;
			}
		return res;
	}
};


//分治法
class Solution {
public:
	int longestSubstring(string s, int k) {
		int n = s.size(), res = 0, max_idx = 0;
		int m[26] = { 0 };
		bool judge = true;
		for (int i = 0; i<s.size(); ++i)
		{
			++m[s[i] - 'a'];
		}
		for (int i = 0; i<n; ++i)
		{
			if (m[s[i] - 'a']<k)
			{
				res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
				judge = false;
				max_idx = i + 1;
			}
		}
		return judge ? n : max(res, longestSubstring(s.substr(max_idx, n - max_idx), k));
	}
};