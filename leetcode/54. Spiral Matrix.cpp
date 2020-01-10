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