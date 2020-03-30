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
#include<math.h>
using namespace std;

//��1����ǰ���ֻ꣬��ĸţ�ſ���������
//
//��2����Ϊ���е�ţ������������ˣ���N - 1�������ţdp[N - 1]������N�ꡣ
//
//��3����Ϊ�����ĸţÿ�궼���� 1 ͷСĸţ����ˣ���N - 3���е�����ţ����N�궼������һ��Сĸţ��dp[N - 3]��
//
//N ���ţ��������Ϊ��һֱ�Ĵ�ĸţdp[N - 1] + ������Сĸţdp[N - 3]��


int main()
{
	long long n;
	long m = 1e9 + 7;
	cin >> n;
	vector<long long> dp(n + 1, 0);
	if (n == 1 || n == 2 || n == 3)
	{
		cout << n;
		return 0;
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 3]) % m;
	}
	cout << dp[n];
	return 0;
}


//���Ϳռ临�Ӷ�
int main()
{
	long long n;
	long m = 1e9 + 7;
	cin >> n;
	if (n == 1 || n == 2 || n == 3)
	{
		cout << n;
		return 0;
	}
	int a = 1, b = 2, c = 3;
	for (int i = 4; i <= n; ++i)
	{
		int tmp1 = (a + c) % m;
		a = b;
		b = c;
		c = tmp1;
	}
	cout << c;
	return 0;
}