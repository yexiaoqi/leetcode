class Solution {
public:
	int countPrimes(int n) {
		if (n<2)
		{
			return 0;
		}
		int res = 0;
		vector<bool> prime(n, true);
		for (int i = 2; i<n; ++i)
		{
			if (!prime[i])
			{
				continue;
			}
			++res;
			for (int j = 2; i*j<n; ++j)
			{
				prime[i*j] = false;
			}
		}
		return res;
	}
};