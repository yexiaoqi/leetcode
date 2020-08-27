//思路类似于剑指offer57_2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, k;
	cin >> N >> k;
	if (N == 0)
	{
		return 0;
	}
	vector<int> nums(N, 0);
	for (int i = 0; i<N; ++i)
	{
		cin >> nums[i];
	}
	int left = 0, right = 0;
	int sum = nums[0];
	int maxlen = 0;
	while (right<N)
	{
		if (sum<k)
		{
			++right;
			sum += nums[right];
		}
		else if (sum == k)
		{
			int cnt = right - left + 1;
			if (maxlen<cnt)
			{
				maxlen = cnt;
			}
			++right;
			if (right<N)
			{
				sum += nums[right];
			}
		}
		else
		{
			sum -= nums[left];
			++left;
		}
	}
	cout << maxlen;
	return 0;
}