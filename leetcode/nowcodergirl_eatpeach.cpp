#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100010;
//int x[N],y[N];
vector<int> a[N];
bool st[N];
vector<int> ans;
vector<int> w[N];
int dfs(int k)
{
	st[k] = true;
	int mx = 0;
	for (auto it : a[k])
	{
		if (st[it] == true)
		{
			w[k].push_back(-1);
			continue;
		}
		int v = dfs(it);
		st[it] = false;
		w[k].push_back(v);
		mx = max(mx, v);
	}
	return mx + 1;
}
void getans(int k)
{
	ans.push_back(k);
	st[k] = true;
	int mxid = -1, mxval = -1;
	for (int i = 0; i<a[k].size(); ++i)
	{
		int it = a[k][i];
		if (st[it] == true)
		{
			continue;
		}
		if (w[k][i]>mxval)
		{
			mxid = it;
			mxval = w[k][i];
		}
	}
	if (mxid == -1)
	{
		return;
	}
	getans(mxid);
	st[k] = false;
}
int main()
{
	int n, k;
	cin >> n >> k;
	int  x, y;
	for (int i = 0; i<n - 1; ++i)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(k);
	getans(k);
	for (auto it : ans)
	{
		cout << it << endl;
	}
	return 0;
}