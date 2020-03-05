class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) :grid(n, vector<int>(n, 0))
	{

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int i = 0, j = 0, n = grid.size();
		grid[row][col] = player;
		for (; i<n; ++i)
		{
			if (grid[i][col] != player)
			{
				break;
			}
		}
		if (i == n)
		{
			return player;
		}
		for (; j<n; ++j)
		{
			if (grid[row][j] != player)
			{
				break;
			}
		}
		if (j == n)
		{
			return player;
		}
		if (row == col)
		{
			for (i = 0; i<n; ++i)
			{
				if (grid[i][i] != player)
				{
					break;
				}
			}
		}
		if (i == n)
		{
			return player;
		}
		if (row + col == n - 1)
		{
			for (i = 0; i<n; ++i)
			{
				if (grid[i][n - 1 - i] != player)
				{
					break;
				}
			}
		}
		if (i == n)
		{
			return player;
		}
		return 0;
	}
private:
	vector<vector<int>> grid;
};

/**
* Your TicTacToe object will be instantiated and called as such:
* TicTacToe* obj = new TicTacToe(n);
* int param_1 = obj->move(row,col,player);
*/


//更好的方法
//我们建立一个大小为n的一维数组rows和cols，还有变量对角线diag和逆对角线rev_diag，
//这种方法的思路是，如果玩家1在第一行某一列放了一个子，那么rows[0]自增1，
//如果玩家2在第一行某一列放了一个子，则rows[0]自减1，那么只有当rows[0]等于n或者 - n的时候，
//表示第一行的子都是一个玩家放的，则游戏结束返回该玩家即可，其他各行各列，对角线和逆对角线都是这种思路
class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) :rows(n, 0), cols(n, 0), diag(0), rediag(0)
	{

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int add = player == 1 ? 1 : -1;
		int n = rows.size();
		rows[row] += add;
		cols[col] += add;
		diag += (row == col ? add : 0);
		rediag += (row + col == n - 1 ? add : 0);
		if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(rediag) == n)
		{
			return player;
		}
		return 0;
	}
private:
	vector<int> rows;
	vector<int> cols;
	int diag, rediag;
};

/**