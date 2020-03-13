#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <memory>
#include<time.h>
using namespace std;
class Solution
{
public:
	int randam1to5()
	{
		//srand((unsigned)time(NULL));
		int res = rand() % 5 + 1;
		return res;
	}
	int randam1to7()
	{
		while (true)
		{
			int num = (randam1to5() - 1) * 5 + randam1to5() - 1;
			if (num <= 20)
			{
				return num % 7 + 1;
			}
		}
		/*int num = 0;
		while (num > 20)
		{
		num = (randam1to5() - 1) * 5 + randam1to5() - 1;
		}
		return num % 7 + 1;*/
	}
};
const int MAXNUM = 10000;
int main()
{
	vector<int> cnt(8, 0);
	Solution s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXNUM; ++i)
	{
		int num = s.randam1to7();
		++cnt[num];
	}
	int cntall = 0;
	for (int i = 1; i < cnt.size(); ++i)
	{
		cntall += cnt[i];
		cout << cnt[i] << endl;
	}
	if (cntall != MAXNUM)
	{
		cout << "false";
	}
	else
	{
		cout << "true";
	}
	return 0;
}