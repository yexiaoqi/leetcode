//Í¬Ö¸ÄÏ8¡ª¡ª3
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return{};
		}
		vector<int> res;
		int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0, k = 0;
		vector<vector<int>> di{ { -1,1 },{ 1,-1 } };
		for (int i = 0; i<m*n; ++i)
		{
			res.push_back(matrix[r][c]);
			r += di[k][0];
			c += di[k][1];
			if (r >= m)
			{
				r = m - 1;
				c += 2;
				k = 1 - k;
			}
			if (c >= n)
			{
				c = n - 1;
				r += 2;
				k = 1 - k;
			}
			if (r<0)
			{
				r = 0;
				k = 1 - k;
			}
			if (c<0)
			{
				c = 0;
				k = 1 - k;
			}
		}
		return res;
	}
};