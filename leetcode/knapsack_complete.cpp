//f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
//有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是c[i]，价值是w[i]
//f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
//有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是c[i]，价值是w[i]
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