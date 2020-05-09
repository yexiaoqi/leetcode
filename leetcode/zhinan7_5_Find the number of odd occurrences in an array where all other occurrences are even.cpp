//基本同leetcode136
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n;
	//vector<int> nums(n,0);//建立数组会超过内存限制
	cin >> n;
	int result;
	cin >> result;
	for (int i = 1; i<n; ++i)
	{
		int tmp;
		cin >> tmp;
		result ^= tmp;
	}
	cout << result;
	return 0;
}