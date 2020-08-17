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
#include <sstream>
using namespace std;
int main()
{
	int N, d;
	cin >> N >> d;
	vector<vector<int>> nums(N, vector<int>(N, 0));
	vector<vector<int>> diff(N, vector<int>(N, 0));
	int first = 0;
	bool judge = true;
	int maxnum = INT_MIN;
	long cnt = 0;
	long cnt2 = 0;
	for (int i = 0; i<N; ++i)
	{
		for (int j = 0; j<N; ++j)
		{
			cin >> nums[i][j];
			if (i == 0 && j == 0)
			{
				first = nums[0][0];
				if (maxnum<first)
				{
					maxnum = first;
				}
			}
			else
			{
				if (first != nums[i][j])
				{
					judge = false;
				}
				if (maxnum<nums[i][j])
				{
					maxnum = nums[i][j];
				}
			}
		}
	}
	if (judge)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i<N; ++i)
	{
		for (int j = 0; j<N; ++j)
		{
			diff[i][j] = maxnum - nums[i][j];
			if (diff[i][j] % d != 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				cnt2 = cnt2 + (maxnum - nums[i][j]) / d;
			}
		}
	}
	cout << cnt2;
	return 0;
}