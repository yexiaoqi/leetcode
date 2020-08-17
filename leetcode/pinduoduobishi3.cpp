//Í¨¹ý85%
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<limits.h>
#include<math.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
	{
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main()
{
	int N, M, T;
	cin >> N >> M >> T;
	vector<pair<int, int>> lunch(N);
	vector<pair<int, int>> dinner(M);
	for (int i = 0; i<N; ++i)
	{
		cin >> lunch[i].first >> lunch[i].second;
	}
	for (int i = 0; i<M; ++i)
	{
		cin >> dinner[i].first >> dinner[i].second;
	}
	sort(lunch.begin(), lunch.end(), compare);
	sort(dinner.begin(), dinner.end(), compare);
	int hot = INT_MAX;
	int i = 0, j = 0;
	for (; i<N; ++i)
	{
		if (lunch[i].second >= T)
		{
			hot = min(hot, lunch[i].first);
		}
		else
		{
			break;
		}
	}
	for (; j<M; ++j)
	{
		if (dinner[i].second >= T)
		{
			hot = min(hot, dinner[i].first);
		}
		else
		{
			break;
		}
	}
	int tmpj = j;
	for (; i<N; ++i)
	{
		j = tmpj;
		/*int tmp3 = lunch[i].second + dinner[j].second;
		if (tmp3<T)
		{
		break;
		}*/
		for (; j<M; ++j)
		{
			int tmp = lunch[i].second + dinner[j].second;
			int tmp2 = lunch[i].first + dinner[j].first;
			if (tmp >= T)
			{
				hot = min(hot, tmp2);
			}
			else
			{
				break;
			}
		}
	}
	if (hot == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << hot;
	}
	return 0;
}