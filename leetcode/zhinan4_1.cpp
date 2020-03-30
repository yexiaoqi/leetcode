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

//（1）在前三年，只有母牛才可以生产。
//
//（2）因为所有的牛都不会死，因此，第N - 1年的所有牛dp[N - 1]都会活到第N年。
//
//（3）因为成熟的母牛每年都会生 1 头小母牛。因此，第N - 3年中的所有牛到第N年都会新增一个小母牛。dp[N - 3]。
//
//N 年后牛的总数量为：一直的大母牛dp[N - 1] + 新增的小母牛dp[N - 3]。


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


//降低空间复杂度
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