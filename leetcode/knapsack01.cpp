//f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
//result[i][j] = max(result[i - 1][j], result[i - 1][j - weight_array[i]] + value_array[i]);
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
			res[j] = max(res[j], res[j - volume[i]] + worth[i]);
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