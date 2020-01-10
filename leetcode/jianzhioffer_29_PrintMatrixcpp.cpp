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


//����������
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> res;
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return vector<int>();
		}
		int start = 0;
		int rows = matrix.size(), cols = matrix[0].size();
		while (rows>start * 2 && cols>start * 2)
		{
			clockwise(matrix, rows, cols, start, res);
			++start;
		}
		return res;
	}
	void clockwise(vector<vector<int>>& matrix, int rows, int cols, int start, vector<int> &res)
	{
		int endx = cols - 1 - start;
		int endy = rows - 1 - start;
		for (int i = start; i <= endx; ++i)
		{
			res.push_back(matrix[start][i]);
		}
		if (endy>start)
		{
			for (int i = start + 1; i <= endy; ++i)
			{
				res.push_back(matrix[i][endx]);
			}
		}
		if (endy>start&&endx>start)
		{
			for (int i = endx - 1; i >= start; --i)
			{
				res.push_back(matrix[endy][i]);
			}
		}
		if (endy>start + 1 && endx>start)
		{
			for (int i = endy - 1; i >= start + 1; --i)
			{
				res.push_back(matrix[i][start]);
			}
		}
	}
};