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
	vector<int> nums(n);
	int odd = 1, eval = 0;
	for (int i = 0; i<n; ++i)
	{
		cin >> nums[i];
	}
	int end = n - 1;
	while (odd<n&&eval<n)
	{
		if (nums[end] % 2 == 0)
		{
			swap(nums[eval], nums[end]);
			eval += 2;
		}
		else
		{
			swap(nums[odd], nums[end]);
			odd += 2;
		}
	}
	for (int i = 0; i<n; ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}