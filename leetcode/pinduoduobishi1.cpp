
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
int main()
{
	int K, N;
	cin >> K >> N;
	vector<int> nums(N, 0);
	for (int i = 0; i<N; ++i)
	{
		cin >> nums[i];
	}
	if (K == 0)
	{
		cout << "paradox";
		return 0;
	}
	int res = K;
	int cnt = 0;
	for (int i = 0; i<N; ++i)
	{
		res = res - nums[i];
		if (res<0)
		{
			++cnt;
			res = -res;
		}
		if (res == 0 && i != N - 1)
		{
			cout << "paradox";
			return 0;
		}
	}
	cout << res << " " << cnt;
	return 0;
}