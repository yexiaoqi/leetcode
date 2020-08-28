//https://www.nowcoder.com/questionTerminal/c7d5def10ad942629df21483c89118df
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
#include<sstream>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
	}
	int i = 1;
	while (i<n)
	{
		if (nums[i] != i)
		{
			swap(nums[i], nums[nums[i]]);
		}
		else
		{
			++i;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}