//��ʼ��������leetcode����08.06

//��������
//ʱ�临�Ӷ�o(n),�ռ临�Ӷ�o(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int FindStep(vector<int> pos, int i, int from, int mid, int to)
{
	if (i == -1)
	{
		return 0;
	}
	if (pos[i] != from&&pos[i] != to)
	{
		return -1;
	}
	if (pos[i] == from)
	{
		return FindStep(pos, i - 1, from, to, mid);
	}
	else
	{
		long rest = FindStep(pos, i - 1, mid, from, to);
		if (rest == -1)
		{
			return -1;
		}
		return ((1 << i) + rest) % 1000000007;//pow������ҪΪ������,�ӷ����ȼ�����<<����Ҫ������
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> pos(n, 0);
	if (n == 0)
	{
		return -1;
	}
	for (int i = 0; i<n; ++i)
	{
		cin >> pos[i];
	}
	cout << FindStep(pos, n - 1, 1, 2, 3);
	return 0;
}




//ʱ�临�Ӷ�o(n),�ռ临�Ӷ�o(1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> pos(n, 0);
	if (n == 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i<n; ++i)
	{
		cin >> pos[i];
	}
	int from = 1, mid = 2, to = 3;
	long res = 0;
	int i = n - 1;
	int last = 1;
	vector<int> helper(n);
	for (int i = 0; i<n; ++i)
	{
		helper[i] = last;
		last = (last << 1) % 1000000007;
	}//�����ڹ����оͺܴ����Բ���ֻ�ں���%1000000007
	while (i >= 0)
	{
		if (pos[i] != from&&pos[i] != to)
		{
			cout << -1;
			return 0;
		}
		if (pos[i] == to)
		{
			//res=(res+(1<<i))%1000000007;
			res = (res + helper[i]) % 1000000007;
			swap(from, mid);
		}
		else
		{
			swap(to, mid);
		}
		--i;
	}
	cout << res % 1000000007;
	return 0;
}