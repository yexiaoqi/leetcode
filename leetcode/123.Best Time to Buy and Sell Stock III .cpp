//自己的做法，超时
//遍历划分点，把数组分成两部分，分别计算两部分的最大利润
class Solution {
public:
	int Oneprofit(vector<int>& prices, int begin, int end)
	{
		if (prices.size() == 0)
		{
			return 0;
		}
		int minprice = prices[begin];
		int res = 0;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (res<prices[i] - minprice)
			{
				res = prices[i] - minprice;
			}
			if (minprice>prices[i])
			{
				minprice = prices[i];
			}
		}
		return res;
	}
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n<2)
		{
			return 0;
		}
		int res = 0;
		for (int i = 1; i<n - 1; ++i)
		{
			int sum1 = Oneprofit(prices, 0, i);
			int sum2 = Oneprofit(prices, i + 1, n - 1);
			if (res<sum1 + sum2)
			{
				res = sum1 + sum2;
			}
		}
		int sum3 = Oneprofit(prices, 0, n - 1);//如果一定买卖两次，那么不需要这个sum2，但是像1,2,3,4,5买卖一次比两次获得的金钱更多
		//当然如果上面i从1开始，到n-1结束，就不用sum3了
		if (res<sum3)
		{
			res = sum3;
		}
		return res;
	}
};


//遍历划分点，把数组分成两部分，分别计算两部分的最大利润
//思想还是那个思想，就是用有点像接雨水那道题，把值都存下来，这样就不用反复已经算过的值了，然后划分的
//后半部分从后往前遍历，存的最大值
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}

		int minprice = prices[0];
		vector<int> sum1(n, 0);
		int res1 = 0;
		for (int i = 0; i<n; ++i)
		{
			if (res1<prices[i] - minprice)//不能是if(sum1[i]<prices[i]-minprice),因为sum1[i]更新前是0
			{
				res1 = prices[i] - minprice;
			}
			sum1[i] = res1;
			if (minprice>prices[i])
			{
				minprice = prices[i];
			}
		}


		int maxprice = prices[n - 1];
		int res2 = 0;
		vector<int> sum2(n, 0);
		for (int i = n - 1; i >= 0; --i)
		{
			if (res2<maxprice - prices[i])
			{
				res2 = maxprice - prices[i];
			}
			sum2[i] = res2;
			if (maxprice<prices[i])
			{
				maxprice = prices[i];
			}
		}
		int res = 0;
		for (int i = 0; i<n; ++i)
		{
			if (res<sum1[i] + sum2[i])
			{
				res = sum1[i] + sum2[i];
			}
		}
		return res;
	}
};


//模板
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//我们想求的最终答案是 dp[n - 1][K][0]，即最后一天，最多允许 K 次交易，最多获得多少利润。读者可能问为什么不是 dp[n - 1][K][1]？因为 [1] 代表手上还持有股票，[0] 表示手上的股票已经卖出去了，很显然后者得到的利润一定大于前者。
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
		// dp[0][k][0]：第0天手中持有现金，本质上是没有产生交易，利润是dp[0][k][0]=0。而交易多次k是不可能发生的。
		//dp[0][k][1]：第0天手中持有股票，即将手中现金换成了股票，因此利润减少了prices[0]。
		for (int i = 0; i<n; ++i)
		{
			for (int k = 1; k <= 2; ++k)
			{
				if (i == 0)
				{
					dp[i][k][0] = 0;
					dp[i][k][1] = -prices[0];
				}
				else
				{
					dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
					dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
				}
			}
		}
		return dp[n - 1][2][0];
	}
};


//模板通解
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int n = prices.size();
		int k = 2;
		if (k <= 0 || n <= 1)
		{
			return 0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
		for (int i = 0; i<n; ++i)
		{
			for (int m = 1; m <= k; ++m)
			{
				if (i == 0)
				{
					dp[i][m][0] = 0;
					dp[i][m][1] = -prices[i];
				}
				else
				{
					dp[i][m][0] = max(dp[i - 1][m][0], dp[i - 1][m][1] + prices[i]);
					dp[i][m][1] = max(dp[i - 1][m][1], dp[i - 1][m - 1][0] - prices[i]);
				}
			}
		}
		return dp[n - 1][k][0];
	}
};