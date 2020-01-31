//同leetcode54
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


//这样清晰点
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


//复习，自己做出
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		if (matrix.empty() || matrix[0].empty())
		{
			return res;
		}
		int start = 0;
		int rowsize = matrix.size(), colsize = matrix[0].size();
		while (start * 2<rowsize&&start * 2<colsize)
		{
			Order(matrix, start, res);
			++start;
		}
		return res;
	}
	void Order(vector<vector<int> > &matrix, int start, vector<int> &res)
	{
		int row = start;
		int col = start;
		int rowend = matrix.size() - start, colend = matrix[0].size() - start;
		for (col; col<colend; ++col)
		{
			res.push_back(matrix[row][col]);
		}
		++row;
		--col;
		if (rowend - 1 - start >= 1)
		{
			for (row; row<rowend; ++row)
			{
				res.push_back(matrix[row][col]);
			}
			--row;
			--col;
		}
		if ((rowend - 1 - start >= 1) && (colend - 1 - start >= 1))
		{
			for (col; col >= start; --col)
			{
				res.push_back(matrix[row][col]);
			}
			++col;
			--row;
		}
		if ((rowend - 1 - start >= 2) && (colend - 1 - start >= 1))
		{
			for (row; row>start; --row)
			{
				res.push_back(matrix[row][col]);
			}
		}
	}
};