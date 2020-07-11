//https://windliang.cc/2019/06/24/%E4%B8%80%E6%96%87%E8%AE%A9%E4%BD%A0%E5%BD%BB%E5%BA%95%E6%98%8E%E7%99%BD%E9%A9%AC%E6%8B%89%E8%BD%A6%E7%AE%97%E6%B3%95/
//马拉车算法的第一步是预处理，做法是在每一个字符的左右都加上一个特殊字符，比如加上 '#'
//然后要在前面增加一个字符，这个字符不能是#号，也不能是s中可能出现的字符，所以我们暂且就用美元号吧
//最长子串的长度是回文串半径减1，起始位置是中间位置减去半径再除以2。
//O（n)复杂度
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		//p[i] 表示以 t[i] 字符为中心的回文子串的半径
		int p[t.size()] = { 0 }, id = 0, mx = 0, resId = 0, resMx = 0;
//需要新增两个辅助变量 mx 和 id，其中 id 为能延伸到最右端的位置的那个回文子串的中心点位置，
//mx 是回文串能延伸到的最右端的位置，需要注意的是，这个 mx 位置的字符不属于回文串
//，所以才能用 mx - i 来更新 p[i] 的长度而不用加1
		for (int i = 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//超出R碰到左边界时，选mx-i
			//对于 mx <= i 的情况，无法对 P[i] 做更多的假设，只能 P[i] = 1，然后再去匹配了。

//当 mx - i > P[j] 的时候，以 S[j] 为中心的回文子串包含在以 S[id] 为中心的回文子串中，由于 i 和 j 对称，
//以 S[i] 为中心的回文子串必然包含在以 S[id] 为中心的回文子串中，所以必有 P[i] = P[j]，其中 j = 2 * id - i，
//因为 j 到 id 之间到距离等于 id 到 i 之间到距离，为 i - id，所以 j = id - (i - id) = 2 * id - i


//当 P[j] >= mx - i 的时候，以 S[j] 为中心的回文子串不一定完全包含于以 S[id] 为中心的回文子串中，
//但是基于对称性可知，下图中两个绿框所包围的部分是相同的，也就是说以 S[i] 为中心的回文子串，
//其向右至少会扩张到 mx 的位置，也就是说 P[i] = mx - i。至于 mx 之后的部分是否对称，就只能老老实实去匹配了，
//这就是后面紧跟到 while 循环的作用。
			while (t[i + p[i]] == t[i - p[i]]) ++p[i];//碰到左边界时，右边还可以继续扩展
			//因为p[i] 表示以 t[i] 字符为中心的回文子串的半径，所以p[i]肯定小于i，所以不用i - p[i]>=0&&;然后也是i必须从1开始的原因，否则i=0,p=1,还是会越界的
			//如果i从0开始那么while(i-p[i]>=0&&t[i+p[i]]==t[i-p[i]])
			if (mx < i + p[i]) //当求出的 P [ i ] 的右边界大于当前右边界mx时
			{
				mx = i + p[i];
				id = i;
			}
			if (resMx < p[i]) //resMx是半径
			{
				resMx = p[i];
				resId = i;
			}
		}
		return s.substr((resId - resMx) / 2, resMx - 1);//最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2。
	}
};

//方法二 O(n^2)复杂度，就要以每一个字符为中心，像两边扩散来寻找回文串，分奇偶讨论
//以每一个字符为中心，像两边扩散来寻找回文串，这个算法的时间复杂度是 O(n*n)，可以通过 OJ，
//就是要注意奇偶情况，由于回文串的长度可奇可偶，比如 "bob" 是奇数形式的回文，"noon" 就是偶数形式的回文，
//两种形式的回文都要搜索，对于奇数形式的，我们就从遍历到的位置为中心，向两边进行扩散，对于偶数情况，
//我们就把当前位置和下一个位置当作偶数行回文的最中间两个字符，然后向两边进行搜索
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size()<2)
		{
			return s;
		}
		int n = s.size(), maxlen = 0, start = 0;
		for (int i = 0; i<n - 1; ++i)
		{
			FindPalinrome(s, i, i, start, maxlen);
			FindPalinrome(s, i, i + 1, start, maxlen);
		}
		return s.substr(start, maxlen);
	}

	void FindPalinrome(string s, int left, int right, int &start, int &maxlen)
	{
		while (left >= 0 && right<s.size() && s[left] == s[right])
		{
			--left;
			++right;
		}
		if (maxlen<right - left - 1)
		{
			start = left + 1;
			maxlen = right - left - 1;
		}
	}
};


//复习
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i<s.size(); ++i)
		{
			// //t+='#'+s[i];//这样写是错的
			t += s[i];
			t += '#';
		}
		int mx = 0, id = 0, resmx = 0, resid = 0;
		vector<int> p(t.size(), 0);
		for (int i = 0; i<t.size(); ++i)
		{
			p[i] = mx>i ? min(p[2 * id - i], mx - i) : 1;
			while (i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
			{
				++p[i];
			}
			if (mx<i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
			if (resmx<p[i])
			{
				resmx = p[i];
				resid = i;
			}
		}
		return s.substr((resid - resmx) / 2, resmx - 1);
	}
};


//复习，自己写的解法
class Solution {
public:
	string longestPalindrome(string s) {
		int maxcnt = 0;
		string maxstr = "";
		for (int i = 0; i<s.size(); ++i)
		{
			int cnt = 1;
			int begin = i - 1, end = i + 1;
			while (begin >= 0 && end<s.size() && s[begin] == s[end])
			{
				cnt += 2;
				--begin;
				++end;
			}

			int cnt2 = 0;
			int begin2 = i, end2 = i + 1;
			if (end2<s.size() && s[begin2] == s[end2])
			{
				cnt2 = 2;
				--begin2;
				++end2;
				while (begin2 >= 0 && end2<s.size() && s[begin2] == s[end2])
				{
					cnt2 += 2;
					--begin2;
					++end2;
				}
			}
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				maxstr = s.substr(begin + 1, maxcnt);
			}
			if (maxcnt<cnt2)
			{
				maxcnt = cnt2;
				maxstr = s.substr(begin2 + 1, maxcnt);
			}
		}
		return maxstr;
	}
};


//复习
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$";
		for (int i = 0; i<s.size(); ++i)
		{
			t += '#';
			t += s[i];
		}
		t += '#';
		int id = 0, mx = 0, resid = 0, resmx = 0;
		vector<int> p(t.size(), 0);
		for (int i = 0; i<t.size(); ++i)
		{
			p[i] = mx>i ? min(p[id * 2 - i], mx - i) : 1;
			while (i - p[i] >= 0 && i + p[i]<t.size() && t[i + p[i]] == t[i - p[i]])
			{
				++p[i];
			}
			if (mx<i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
			if (resmx<p[i])
			{
				resmx = p[i];
				resid = id;
			}
		}
		return s.substr((resid - resmx) / 2, resmx - 1);
	}
};

//复习，自己的写法
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
		{
			return s;
		}
		string res = "";
		int maxcnt = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			string str = palindrome(s, i - 1, i + 1);
			int cnt = str.size();
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				res = str;
			}
			str = palindrome(s, i, i + 1);
			cnt = str.size();
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				res = str;
			}
		}
		return res;
	}
	string palindrome(string s, int begin, int end)
	{
		while (begin >= 0 && end<s.size() && s[begin] == s[end])
		{
			--begin;
			++end;
		}
		if (begin + 1 >= s.size())
		{
			return "";
		}
		return s.substr(begin + 1, end - begin - 1);
	}
};