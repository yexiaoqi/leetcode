#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <memory>
#include<time.h>
using namespace std;


//�ó���ⷨ
//��֪��������ɺ���1~m,Ҫ�õ�������ɺ���1~n
class Solution
{
public:
	int random01p()
	{
		double p = 0.83;
		return rand() / double(RAND_MAX) < p ? 0 : 1;
	}
	int rand01()
	{
		int num;
		num = random01p();
		while (num == random01p())
		{
			num = random01p();
		}
		return num;
	}
	int rand12()
	{
		return rand01() + 1;
	}
	int rand1tom(int m)
	{
		return rand() % m + 1;
	}
	int rand1ton(int m, int n)
	{
		if (m < 1 || n < 1)
		{
			return -1;
		}
		if (m < 2)
		{
			return 1;
		}
		if (m == n)
		{
			return rand1tom(m);
		}
		int k = 0, maxm = 0;
		while (maxm + 1 < n)
		{
			k = k*m + rand1tom(m) - 1;
			maxm = m*maxm + m - 1;
			if (maxm + 1 >= n&&k >= ((maxm + 1) / n*n))
			{
				k = 0;
				maxm = 0;
			}
		}
		return k / ((maxm + 1) / n) + 1;
	}
};
const int MAXNUM = 10000;
int main()
{

	vector<int> cnt(10, 0);
	Solution s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXNUM; ++i)
	{
		int num = s.rand1ton(2, 6);
		++cnt[num];
	}
	int cntall = 0;
	for (int i = 0; i < cnt.size(); ++i)
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












//����ⷨ
class Solution
{
public:
	int random01p()
	{
		double p = 0.83;
		return rand() / double(RAND_MAX) < p ? 0 : 1;
	}
	int rand01()
	{
		int num;
		num = random01p();
		while (num == random01p())
		{
			num = random01p();
		}
		return num;
	}
	int rand03()
	{
		return rand01() * 2 + rand01();
	}
	int rand1to6()
	{
		int num = rand03() * 4 + rand03();
		while (true)
		{
			if (num <= 11)
			{
				return num % 6 + 1;
			}
			num = rand03() * 4 + rand03();
		}
		return num;
	}
};
const int MAXNUM = 10000;
int main()
{

	vector<int> cnt(7, 0);
	Solution s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXNUM; ++i)
	{
		int num = s.rand1to6();
		++cnt[num];
	}
	int cntall = 0;
	for (int i = 0; i < cnt.size(); ++i)
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