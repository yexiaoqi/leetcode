//基本和leetcode137一致，只不过把3改成k
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i<n; ++i)
	{
		cin >> nums[i];
	}
	vector<int> count(32, 0);
	int result = 0;
	for (int i = 0; i<32; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			count[i] += (nums[j] >> i) & 0x1;
		}
		count[i] %= k;
	}
	for (int i = 0; i<32; ++i)
	{
		result |= (count[i] << i);
	}
	cout << result;
	return 0;
}