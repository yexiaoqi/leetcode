
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
#include<math.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	vector<pair<int, vector<int>>> nums(T, pair<int, vector<int>>());

	for (int i = 0; i<T; ++i)
	{
		cin >> nums[i].first;
		int cnt0 = 0, cnt1 = 0;
		for (int j = 0; j<nums[i].first; ++j)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 0)
			{
				++cnt0;
			}
			if (tmp == 1)
			{
				++cnt1;
			}
			nums[i].second.push_back(tmp);
		}
		int res = nums[i].first - cnt0;
		if (cnt0 + cnt1 >= nums[i].first)
		{
			res = -1;
		}
		if (res<1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << (res + 1) << endl;
		}
	}
	return 0;
}