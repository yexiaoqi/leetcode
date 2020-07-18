#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <memory>
#include<time.h>
using namespace std;
//都是去拼一个0~x，然后在扩大x+1倍，然后这两个相加，然后超出范围的while循环直到进入范围，然后除余，然后再加个1什么的
//比如1~5要变成1~7，先把1~5变成0~4，然后扩大5倍，有0,5,10,15,20，然后和0~4相加，得到均匀概率的0~24，然后大于20的
//进入循环直到他们在0~20之间，然后除以7得到0~6，然后再加一得到0~7
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