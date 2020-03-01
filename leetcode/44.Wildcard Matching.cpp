//iStar 和 jStar 均初始化为 - 1，表示默认情况下是没有星号的。
//然后再用两个变量i和j分别指向当前s串和p串中遍历到的位置。

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, istar = -1, jstar = -1, m = s.size(), n = p.size();
		while (i<m)//开始进行匹配，若i小于s串的长度，进行 while 循环
		{
			if (j<n && (p[j] == s[i] || p[j] == '?'))
			{
				++i, ++j;//若当前两个字符相等，或着p中的字符是问号，则i和j分别加1
			}
			else if (j<n&&p[j] == '*')//若 p[j] 是星号，要记录星号的位置，jStar 赋为j，此时j再自增1，iStar 赋为i
			{
				istar = i;//iStar表示星号匹配到s串中的位置,就是说匹配到不用*能到达的位置的后一个
				jstar = j;//jstar是p串中星号*的位置
				++j;
			}
			//若当前 p[j] 不是星号，并且不能跟 p[i] 匹配上，此时就要靠星号了，若之前星号没出现过，那么就直接跪;
			//如果星号之前出现过，可以强行续一波命
			////至于如何知道之前有没有星号，这时就能看出 iStar 的作用了，因为其初始化为 - 1，
			//而遇到星号时，其就会被更新为i，只要检测 iStar 的值，就能知道是否可以使用星号续命。
			else if (istar >= 0)
			{
				i = istar;
				++istar;
				j = jstar + 1;
			}
			else
			{
				return false;
			}
		}
//虽然成功续了命，匹配完了s中的所有字符，但是之后还要检查p串，此时没匹配完的p串里只能剩星号，不能有其他的字符，将连续的星号过滤掉，如果j不等于p的长度，则返回 false
		while (j<n&&p[j] == '*')
		{
			++j;
		}
		return j == n;
	}
};


//复习
class Solution {
public:
	bool isMatch(string s, string p) {
		int istar = -1, jstar = -1, m = s.size(), n = p.size(), i = 0, j = 0;
		while (i<m)
		{
			if (j<n && (p[j] == s[i] || p[j] == '?'))
			{
				++i;
				++j;
			}
			else if (j<n&&p[j] == '*')
			{
				istar = i;
				jstar = j;
				++j;
			}
			else if (istar >= 0)
			{
				i = istar;
				++istar;
				j = jstar + 1;
			}
			else
			{
				return false;
			}
		}
		while (j<n&&p[j] == '*')
		{
			++j;
		}
		return j == n;
	}
};