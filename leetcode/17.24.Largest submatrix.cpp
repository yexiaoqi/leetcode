class Solution {
public:
	vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int maxnum = INT_MIN;
		vector<int> sums(n);
		vector<int> res(4);
		for (int i = 0; i<m; ++i)
		{
			for (int t = 0; t<n; ++t)
			{
				sums[t] = 0;
			}
			int beginr1 = i, beginc1 = 0;
			for (int j = i; j<m; ++j)
			{
				int sum = 0;
				for (int k = 0; k<n; ++k)
				{
					sums[k] += matrix[j][k];
					if (sum>0)
					{
						sum += sums[k];
					}
					else
					{
						beginc1 = k;
						sum = sums[k];
					}
					if (maxnum<sum)
					{
						maxnum = sum;
						res[0] = beginr1;
						res[1] = beginc1;
						res[2] = j;
						res[3] = k;
					}
				}
			}
		}
		return res;
	}
};