/*链接：https://ac.nowcoder.com/acm/contest/3405/C
来源：牛客网

题目描述 
牛妹家里有\mathit nn个物品，第\mathit ii个物品体积为v_iv 
i
​	
 ，价值为w_iw 
i
​	
 。牛妹有一个容积无穷大的背包，背包可以装任意多的物品，没有限制。

牛妹要去深山中度假，为了在旁人眼中显得自己准备得很充分，牛妹想在背包中装入总体积不小于\mathit VV的一些物品。如果装入的物品过于贵重，路上如果遇到强盗、劫匪、山贼等就很亏。所以牛妹想知道总体积不小于\mathit VV的前提下，物品的总价值最小是多少。
输入描述:
第一行两个整数\mathit n,Vn,V，表示物品的数量和总体积需求。
接下来\mathit nn行，每行两个整数v_i,w_iv 
i
​	
 ,w 
i
​	
 ，表示第\mathit ii种物品的体积和价值。保证所有物品总体积不小于\mathit VV。
1 \leq n \leq 200, 1 \leq V \leq 10^6, 1 \leq v_i \leq 10^6, 1 \leq w_i \leq 2001≤n≤200,1≤V≤10 
6
 ,1≤v 
i
​	
 ≤10 
6
 ,1≤w 
i
​	
 ≤200。保证所有物品总体积不小于\mathit VV。
输出描述:
输出一个整数，表示答案。*/



//n*v数组，这样空间复杂度太高
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
const int maxn = 2e3 + 3;//203
int n, V, dp[maxn][maxn*maxn];
int v[maxn*maxn], w[maxn];
int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			dp[i][j] = INT_MAX / 2;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			if (j >= v[i])
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[1][0] + w[i]);
			}
		}
	}
	cout << dp[n][V];
	return 0;
}



#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
const int maxn = 2e3 + 3;//203
int n, V, dp[2][maxn*maxn], tmp[maxn];
int v[maxn*maxn], w[maxn];
int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 0; i <2; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			dp[i][j] = INT_MAX / 2;
		}
	}
	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = 1; j <= V; ++j)
	//	{
	//		if (j >= v[i])
	//		{
	//			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
	//		}
	//		else
	//		{
	//			dp[i][j] = min(dp[i - 1][j],dp[1][0]+w[i]);
	//		}
	//	}
	//}


	for (int k = 1; k <= n; ++k)
	{
		for (int j = 1; j <= V; ++j)
		{
			if (j >= v[k])
			{
				dp[1][j] = min(dp[0][j], dp[0][j - v[k]] + w[k]);
			}
			else
			{
				dp[1][j] = min(dp[0][j], w[k]);
			}
		}
		for (int j = 1; j <= V; ++j)
		{
			dp[0][j] = dp[1][j];
		}
	}
	/*for (int k = 1; k <= n; ++k)
	{
	for (int j = 1; j <= V; ++j)
	{
	tmp[j] = dp[0][j];
	if (j >= v[k])
	{
	dp[1][j] = min(tmp[j], tmp[j - v[k]] + w[k]);
	}
	else
	{
	dp[1][j] = min(tmp[j], w[k]);
	}
	dp[0][j] = dp[1][j];
	}
	}*/
	cout << dp[1][V];
	return 0;
}