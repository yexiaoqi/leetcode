//f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
//有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是c[i]，价值是w[i]



//主要代码
class Solution
{
public:
	int knapsack(int N, int V, vector<int>& v, vector<int>& w)
	{
		vector<int> dp(V + 1, 0);
		for (int i = 0; i<N; ++i)
		{
			for (int j = v[i]; j <= V; ++j)
			{
				dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			}
		}
		return dp.back();
	}
};




//主要代码完整版
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int knapsack(int N, int V, vector<int>& v, vector<int>& w)
	{
		vector<int> dp(V + 1, 0);
		for (int i = 0; i<N; ++i)
		{
			for (int j = v[i]; j <= V; ++j)
			{
				dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			}
		}
		return dp.back();
	}
};
int main()
{
	Solution s;
	int N, V;
	cin >> N >> V;
	vector<int> v(N, 0);
	vector<int> w(N, 0);
	for (int i = 0; i<N; ++i)
	{
		cin >> v[i] >> w[i];
	}
	cout << s.knapsack(N, V, v, w);
	return 0;
}






#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int capacity, products_count;
int worth[N], volume[N];
int res[N];

int main()
{
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> volume[i] >> worth[i];
	}

	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = volume[i]; j <= capacity; ++j)//可以一直选第i个，直到体积达到capacity
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);
			//res[j]是没再次选第i个，res[j - volume[i]] + worth[i]是再次选了第i个

		}
	}
	cout << res[capacity];
	return 0;

}


int knapsack(int products_count, int capacity, vector<int>& volume,
	vector<int>& worth, vector<int>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = volume[i]; j <= capacity; ++j)
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);
		}
	}
	return res[capacity];
}


//复习
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int knapsack(int N, int V, vector<int> &v, vector<int> &w)
	{
		vector<int> res(V + 1, 0);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = v[i]; j <= V; ++j)
			{
				res[j] = max(res[j], res[j - v[i]] + w[i]);
			}
		}
		return res[V];
	}
};
int main()
{
	Solution s;
	int N, V;
	cin >> N >> V;
	vector<int> v(N + 1, 0);
	vector<int> w(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i] >> w[i];
	}
	cout << s.knapsack(N, V, v, w);
	return 0;
}