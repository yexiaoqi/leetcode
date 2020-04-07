//https://www.acwing.com/problem/content/2/ 刷题
//f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
//result[i][j] = max(result[i - 1][j], result[i - 1][j - weight_array[i]] + value_array[i]);


//主要代码
class Solution
{
public:
	int FindMaxWorth(vector<int>& v, vector<int>& w, int V)
	{
		vector<int> dp(V + 1, 0);
		for (int i = 0; i<v.size(); ++i)
		{
			for (int j = V; j >= v[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			}
		}
		return dp.back();
	}
};


//主要代码的完整版
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int FindMaxWorth(vector<int>& v, vector<int>& w, int V)
	{
		vector<int> dp(V + 1, 0);
		for (int i = 0; i<v.size(); ++i)
		{
			for (int j = V; j >= v[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
			}
		}
		return dp.back();
	}
};
int main()
{
	int N, V;
	cin >> N >> V;
	vector<int> v(N, 0);
	vector<int> w(N, 0);
	for (int i = 0; i<N; ++i)
	{
		cin >> v[i] >> w[i];
	}
	Solution s;
	int res = s.FindMaxWorth(v, w, V);
	cout << res;
	return 0;
}









///一维数组求解
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
		for (int j = capacity; j >= volume[i]; --j)
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);

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
		for (int j = capacity; j >= volume[i]; --j)
		{
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);//因为要用到它前面的值计算，所以必须逆序
		}
	}
	return  res[capacity];
}





int knapsack(int products_count, int capacity, vector<int>& weight_array, vector<int>& value_array, vector<vector<int>>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (weight_array[i] > j) // 当前背包的容量 j 放不下第 i 件商品时
			{
				result[i][j] = result[i - 1][j]; // 放弃第 i 件商品，拿第 i - 1 件商品
			}
			else
			{
				result[i][j] = max(result[i - 1][j], result[i - 1][j - weight_array[i]] + value_array[i]);
				//result[i - 1][j - weight_array[i]] + value_array[i];  拿走第 i - 1件商品
				//result[i - 1][j];  不拿走第 i - 1 件商品
			}
		}
	}
	return result[products_count][capacity];
}


//二维数组
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int capacity, products_count;
int value[N], weight[N];
int res[N][N];

int main()
{
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (weight[i]>j)
			{
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = max(res[i - 1][j], res[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	cout << res[products_count][capacity];
	return 0;
}




#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int capacity, products_count;
int worth[N], volume[N];
int res[N][N];

int main()
{
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> volume[i] >> worth[i];
	}

	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (volume[i]>j)
			{
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = max(res[i - 1][j], res[i - 1][j - volume[i]] + worth[i]);
			}
		}
	}
	cout << res[products_count][capacity];
	return 0;
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
		vector<vector<int>> res(N + 1, vector<int>(V + 1, 0));
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				if (v[i]>j)
				{
					res[i][j] = res[i - 1][j];
				}
				else
				{
					res[i][j] = max(res[i - 1][j], res[i - 1][j - v[i]] + w[i]);
				}
			}
		}
		return res[N][V];
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
			for (int j = V; j >= v[i]; --j)
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