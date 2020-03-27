//建立一个大小为 numRows 的字符串数组，为的就是把之字形的数组整个存进去，然后再把每一行的字符拼接起来，
//就是想要的结果了。顺序就是按列进行遍历，首先前 numRows 个字符就是按顺序存在每行的第一个位置，
//然后就是 ‘之’ 字形的连接位置了，可以发现其实都是在行数区间[1, numRows - 2] 内，只要按顺序去取字符就可以了
//，最后把每行都拼接起来即为所求
class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> vec(numRows);
		int i = 0, n = s.size();
		while (i<n)
		{
			for (int pos = 0; pos<numRows&&i<n; ++pos)
			{
				vec[pos] += s[i++];
			}
			for (int pos = numRows - 2; pos >= 1 && i<n; --pos)
			{
				vec[pos] += s[i++];
			}
		}
		string res;
		for (int i = 0; i<vec.size(); ++i)
		{
			res += vec[i];
		}
		return res;
	}
};