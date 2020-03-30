//首先给出n个数字a1, a2, ….an，然后给你m个回合，每回合你可以从中选择一个数取走它，剩下来的每个数字ai都要减去一个值bi。如此重复m个回合，所有你拿走的数字之和就是你所得到的分数。
//
//现在给定你a序列和b序列，请你求出最多可以得到多少分。
//
//输入
//输入第一行，仅包含一个整数n（1 <= n <= 100），表示数字的个数。
//
//第二行，一个整数m（1 <= m <= n），表示回合数。
//
//接下来一行有n个不超过10000的正整数，分别为a1, a2…an.
//
//最后一行有n个不超过500的正整数，分别为b1, b2….bn.
//
//输出
//输出仅包含一个正整数，即最多可以得到的分数

//case
//3
//3
//10 20 30
//4 5 6
//注意题目的意思是a和b是绑定的，10是减去4,20是减去5,30是减去6

//可通过的代码
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct data { int a, b; }a[201];
int n, m, f[201][201];
inline bool cmp(data a, data b)
{
	return a.b>b.b;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i].a);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i].b);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + a[i].a - a[i].b*(j - 1));
	printf("%d", f[n][m]);
	return 0;
}




//改成自己的形式
//因为擦走的数字是有顺序的，所以如果可以规定一个序，删除的顺序必需和这个序相对应，就可以用DP了。
//而且我们可以发现，假如a[i]在a[j]前删除，而b[i]小于b[j]的话，那么我们可以交换这两个数的删除顺序而使得总和更大。
//
//所以，第一步就是对数按b[i]从大到小排序。接着，就设F[i, j]表示从前i个删除j个数的最大分值。
//
//因此，动态转移方程就为：
//f[i][j] = max(f[i−1][j], f[i−1][j−1] + a[i]−b[i]∗(j−1)); 
bool compare(pair<int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}
int main()
{
	int numsize, times;
	cin >> numsize >> times;
	vector<pair<int, int>> num(numsize, pair<int, int>());
	for (int i = 0; i<numsize; ++i)
	{
		cin >> num[i].first;
	}
	for (int i = 0; i<numsize; ++i)
	{
		cin >> num[i].second;
	}
	sort(num.begin(), num.end(), compare);
	vector<vector<int>> dp(numsize + 1, vector<int>(times + 1, 0));
	for (int i = 1; i <= numsize; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + num[i - 1].first - num[i - 1].second*(j - 1));
		}
	}
	cout << dp[numsize][times];
	return 0;
}

//不可通过的，只过了一个case的，题意理解不对
int main()
{
	long numsize, times;
	cin >> numsize >> times;
	vector<int> a(numsize, 0);
	vector<int> b(numsize, 0);
	for (int i = 0; i<numsize; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i<numsize; ++i)
	{
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int minus = 0;
	for (int i = 0; i<times - 1; ++i)
	{
		minus += b[i] * (times - i - 1);
	}
	int sum = 0;
	for (int i = 0; i<times; ++i)
	{
		sum += a[i];
	}
	int res = sum - minus;
	cout << res;
	return 0;
}