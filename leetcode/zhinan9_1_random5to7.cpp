#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <memory>
#include<time.h>
using namespace std;
//����ȥƴһ��0~x��Ȼ��������x+1����Ȼ����������ӣ�Ȼ�󳬳���Χ��whileѭ��ֱ�����뷶Χ��Ȼ����࣬Ȼ���ټӸ�1ʲô��
//����1~5Ҫ���1~7���Ȱ�1~5���0~4��Ȼ������5������0,5,10,15,20��Ȼ���0~4��ӣ��õ����ȸ��ʵ�0~24��Ȼ�����20��
//����ѭ��ֱ��������0~20֮�䣬Ȼ�����7�õ�0~6��Ȼ���ټ�һ�õ�0~7
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