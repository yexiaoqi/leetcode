class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		if (int(matrix.size()) == 0)
		{
			return res;
		}
		int endii = int(matrix.size()), endjj = int(matrix[0].size());
		int size = min(int(matrix.size() + 1) / 2, int(matrix[0].size() + 1) / 2);
		--endii; --endjj;
		for (int start = 0; start<size; ++start)
		{
			for (int j = start; j <= endjj; ++j)
			{
				res.push_back(matrix[start][j]);
			}
			if (start<endii)
			{
				for (int i = start + 1; i <= endii; ++i)
				{
					res.push_back(matrix[i][endjj]);
				}
			}
			if (start<endjj&&start<endii)
			{
				for (int j = endjj - 1; j >= start; --j)
				{
					res.push_back(matrix[endii][j]);
				}
			}
			if (start<endjj&&start<(endii - 1))
			{
				for (int i = endii - 1; i >= start + 1; --i)
				{
					res.push_back(matrix[i][start]);
				}
			}
			--endii; --endjj;
		}
		return res;
	}
};