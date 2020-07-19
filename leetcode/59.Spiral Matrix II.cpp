class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n <= 0)
		{
			return vector<vector<int>>();
		}
		vector<vector<int>> res(n, vector<int>(n, 0));
		int start = 0, cnt = 1;
		while (n>2 * start)
		{
			generateMatrix(n, start, cnt, res);
			++start;
		}
		return res;
	}
	void generateMatrix(int n, int start, int &cnt, vector<vector<int>> &res)
	{
		int endx = n - 1 - start;
		int endy = n - 1 - start;
		for (int i = start; i <= endx; ++i)
		{
			res[start][i] = cnt;
			++cnt;
		}
		if (endy>start)
		{
			for (int i = start + 1; i <= endy; ++i)
			{
				res[i][endx] = cnt;
				++cnt;
			}
			for (int i = endx - 1; i >= start; --i)
			{
				res[endy][i] = cnt;
				++cnt;
			}
		}
		if (endx>start + 1)
		{
			for (int i = endy - 1; i>start; --i)
			{
				res[i][start] = cnt;
				++cnt;
			}
		}
	}
};