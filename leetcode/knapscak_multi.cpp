//O(n^3)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int capacity, products_count;
int worth[N], volume[N], s[N];
int res[N];
int main()
{
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> volume[i] >> worth[i] >> s[i];
	}

	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = capacity; j >= volume[i]; --j)
		{
			for (int k = 1; k <= s[i] && k*volume[i] <= j; ++k)
			{
				res[j] = max(res[j], res[j - k*volume[i]] + k*worth[i]);
			}
		}
	}
	cout << res[capacity];
	return 0;
}

//二进制拆法，O(V*Σlog n[i])
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2010;
int capacity, products_count;
int worth[N], volume[N], s[N];
int res[N];
int main()
{
	vector<pair<int, int>> goods;
	cin >> products_count >> capacity;
	for (int i = 1; i <= products_count; ++i)
	{
		cin >> volume[i] >> worth[i] >> s[i];
		for (int k = 1; k <= s[i]; k *= 2)
		{
			s[i] -= k;
			goods.push_back(make_pair(volume[i] * k, worth[i] * k));
		}
		if (s[i]>0)
		{
			goods.push_back(make_pair(volume[i] * s[i], worth[i] * s[i]));
		}
	}
	for (int i = 0; i < goods.size(); ++i)
	{
		for (int j = capacity; j >= goods[i].first; --j)
		{
			res[j] = max(res[j], res[j - goods[i].first] + goods[i].second);
		}
	}
	cout << res[capacity];
	return 0;
}



int knapsack(int products_count, int capacity, vector<int>& volume,
	vector<int>& worth,vector<int> &s, vector<int>& result)
{
	vector<pair<int, int>> goods;
	for (int i = 1; i <= products_count; ++i)
	{
		for (int k = 1; k <= s[i]; k *= 2)
		{
			s[i] -= k;
			goods.push_back(make_pair(volume[i] * k, worth[i] * k));
		}
		if (s[i]>0)
		{
			goods.push_back(make_pair(volume[i] * s[i], worth[i] * s[i]));
		}
	}
	for (int i = 0; i < goods.size(); ++i)
	{
		for (int j = capacity; j >= goods[i].first; --j)
		{
			res[j] = max(res[j], res[j - goods[i].first] + goods[i].second);
		}
	}
	return res[capacity];	 
}