class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size()<2)
		{
			return 0;
		}
		int min = prices[0];
		int maxpro = 0;
		for (int i = 1; i<prices.size(); ++i)
		{
			if (prices[i - 1]<min)
			{
				min = prices[i - 1];
			}
			if (prices[i] - min>maxpro)
			{
				maxpro = prices[i] - min;
			}
		}
		return maxpro;
	}
};