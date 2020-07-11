#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
	int N, k;
	cin >> N >> k;
	vector<int> nums(N, 0);
	for (int i = 0; i<N; ++i)
	{
		cin >> nums[i];
	}
	unordered_map<int, int> m;
	m[0] = -1;
	int maxlen = 0;
	int sum = 0;
	for (int i = 0; i<N; ++i)
	{
		sum += nums[i];
		int tmp = sum - k;
		if (m.count(tmp))
		{
			int len = i - m[tmp];
			if (maxlen<len)
			{
				maxlen = len;
			}
		}
		if (!m.count(sum))
		{
			m[sum] = i;
		}
	}
	cout << maxlen;
	return 0;
}

//²¹³äÎÊÌâ1
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> nums(N, 0);
	for (int i = 0; i<N; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp>0)
		{
			nums[i] = 1;
		}
		else if (tmp<0)
		{
			nums[i] = -1;
		}
	}
	int sum = 0;
	unordered_map<int, int> m;
	int maxlen = 0;
	m[0] = -1;
	for (int i = 0; i<N; ++i)
	{
		sum += nums[i];
		if (m.count(sum))
		{
			int len = i - m[sum];
			if (maxlen<len)
			{
				maxlen = len;
			}
		}
		if (!m.count(sum))
		{
			m[sum] = i;
		}
	}
	cout << maxlen;
	return 0;
}