//https://blog.csdn.net/thecentry/article/details/83042242
//给定两个字符串s1和s2，测定它们之间的相似度。相似度的定义如下：假设s1 = "abcde", s2 = "abcd"，
//那么我们可以经过一次编辑（删掉s1的字符e，或者在s2末尾插入字符e）将它们变为相同的，这个编辑次数称为距离，
//而相似度为1 / (距离 + 1)。
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		string res = "1/";
		int n = (int)a.size(), m = (int)b.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
		dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
		for (int i = 1; i <= m; ++i)
			dp[0][i] = i;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = i;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
				if (a[i - 1] != b[j - 1])
					three += 1;
				dp[i][j] = min(min(one, two), three);
			}
		}
		res += to_string(1 + dp[n][m]);
		cout << res << endl;
	}
	return 0;
}