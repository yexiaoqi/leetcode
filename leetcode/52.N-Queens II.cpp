class Solution {
public:
	int totalNQueens(int n) {
		vector<vector<string>> res;
		vector<string> queens(n, string(n, '.'));
		helper(queens, res, 0);
		return res.size();
	}
	void helper(vector<string> &queens, vector<vector<string>> &res, int currow)
	{
		if (currow == queens.size())
		{
			res.push_back(queens);
			return;
		}
		for (int i = 0; i<queens.size(); ++i)
		{
			if (isValid(queens, currow, i))
			{
				queens[currow][i] = 'Q';
				helper(queens, res, currow + 1);
				queens[currow][i] = '.';
			}
		}
	}
	bool isValid(vector<string> &queens, int row, int col)
	{
		for (int i = 0; i<row; ++i)
		{
			if (queens[i][col] == 'Q')
			{
				return false;
			}
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
		{
			if (queens[i][j] == 'Q')
			{
				return false;
			}
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j<queens.size(); --i, ++j)
		{
			if (queens[i][j] == 'Q')
			{
				return false;
			}
		}
		return true;
	}
};


//¼ò»¯
class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		//vector<string> queens(n,string(n,'.'));
		vector<int> queens(n, -1);
		helper(queens, res, 0);
		return res;
	}
	void helper(vector<int> &queens, int &res, int currow)
	{
		if (currow == queens.size())
		{
			++res;
			return;
		}
		for (int col = 0; col<queens.size(); ++col)
		{
			if (isValid(queens, currow, col))
			{
				//queens[currow][i]='Q';
				queens[currow] = col;
				helper(queens, res, currow + 1);
				//queens[currow][i]='.';
				queens[currow] = -1;
			}
		}
	}
	bool isValid(vector<int> &queens, int row, int col)
	{
		// for(int i=0;i<row;++i)
		// {
		//     if(queens[i][col]=='Q')
		//     {
		//         return false;
		//     }
		// }
		// for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j)
		// {
		//     if(queens[i][j]=='Q')
		//     {
		//         return false;
		//     }
		// }
		// for(int i=row-1,j=col+1;i>=0&&j<queens.size();--i,++j)
		// {
		//     if(queens[i][j]=='Q')
		//     {
		//         return false;
		//     }
		// }
		for (int i = 0; i<row; ++i)
		{
			if (queens[i] == col || (abs(row - i) == abs(col - queens[i])))
			{
				return false;
			}
		}
		return true;
	}
};