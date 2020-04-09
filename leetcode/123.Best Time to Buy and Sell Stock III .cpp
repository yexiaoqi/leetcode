//�Լ�����������ʱ
//�������ֵ㣬������ֳ������֣��ֱ���������ֵ��������
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
		int sum3 = Oneprofit(prices, 0, n - 1);//���һ���������Σ���ô����Ҫ���sum2��������1,2,3,4,5����һ�α����λ�õĽ�Ǯ����
		//��Ȼ�������i��1��ʼ����n-1�������Ͳ���sum3��
		if (res<sum3)
		{
			res = sum3;
		}
		return res;
	}
};


//�������ֵ㣬������ֳ������֣��ֱ���������ֵ��������
//˼�뻹���Ǹ�˼�룬�������е������ˮ�ǵ��⣬��ֵ���������������Ͳ��÷����Ѿ������ֵ�ˣ�Ȼ�󻮷ֵ�
//��벿�ִӺ���ǰ������������ֵ
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
			if (res1<prices[i] - minprice)//������if(sum1[i]<prices[i]-minprice),��Ϊsum1[i]����ǰ��0
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


//ģ��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//������������մ��� dp[n - 1][K][0]�������һ�죬������� K �ν��ף�����ö������󡣶��߿�����Ϊʲô���� dp[n - 1][K][1]����Ϊ [1] �������ϻ����й�Ʊ��[0] ��ʾ���ϵĹ�Ʊ�Ѿ�����ȥ�ˣ�����Ȼ���ߵõ�������һ������ǰ�ߡ�
		//dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
		//dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
		// dp[0][k][0]����0�����г����ֽ𣬱�������û�в������ף�������dp[0][k][0]=0�������׶��k�ǲ����ܷ����ġ�
		//dp[0][k][1]����0�����г��й�Ʊ�����������ֽ𻻳��˹�Ʊ��������������prices[0]��
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


//ģ��ͨ��
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